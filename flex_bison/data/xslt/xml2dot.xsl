<?xml version="1.0" encoding="UTF-8"?>

<!--
    xml2dot.xsl - transform Bison XML Report into DOT.

    Copyright (C) 2007-2015 Free Software Foundation, Inc.

    This file is part of Bison, the GNU Compiler Compiler.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Written by Wojciech Polak <polak@gnu.org>.
  -->

<xsl:stylesheet version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns:bison="http://www.gnu.org/software/bison/">

<xsl:import href="bison.xsl"/>
<xsl:output method="text" encoding="UTF-8" indent="no"/>

<xsl:template match="/">
  <xsl:apply-templates select="bison-xml-report"/>
</xsl:template>

<xsl:template match="bison-xml-report">
  <xsl:text>// Generated by GNU Bison </xsl:text>
  <xsl:value-of select="@version"/>
  <xsl:text>.&#10;</xsl:text>
  <xsl:text>// Report bugs to &lt;</xsl:text>
  <xsl:value-of select="@bug-report"/>
  <xsl:text>&gt;.&#10;</xsl:text>
  <xsl:text>// Home page: &lt;</xsl:text>
  <xsl:value-of select="@url"/>
  <xsl:text>&gt;.&#10;&#10;</xsl:text>
  <xsl:apply-templates select="automaton">
    <xsl:with-param name="filename" select="filename"/>
  </xsl:apply-templates>
</xsl:template>

<xsl:template match="automaton">
  <xsl:param name="filename"/>
  <xsl:text>digraph "</xsl:text>
  <xsl:call-template name="escape">
    <xsl:with-param name="subject" select="$filename"/>
  </xsl:call-template>
  <xsl:text>"&#10;{
  node [fontname = courier, shape = box, colorscheme = paired6]
  edge [fontname = courier]

</xsl:text>
  <xsl:apply-templates select="state"/>
  <xsl:text>}&#10;</xsl:text>
</xsl:template>

<xsl:template match="automaton/state">
  <xsl:call-template name="output-node">
    <xsl:with-param name="number" select="@number"/>
    <xsl:with-param name="label">
      <xsl:apply-templates select="itemset/item"/>
    </xsl:with-param>
  </xsl:call-template>
  <xsl:apply-templates select="actions/transitions"/>
  <xsl:apply-templates select="actions/reductions">
    <xsl:with-param name="staten">
      <xsl:value-of select="@number"/>
    </xsl:with-param>
  </xsl:apply-templates>
</xsl:template>

<xsl:template match="actions/reductions">
  <xsl:param name="staten"/>
  <xsl:for-each select='reduction'>
    <!-- These variables are needed because the current context can't be
         refered to directly in XPath expressions. -->
    <xsl:variable name="rul">
      <xsl:value-of select="@rule"/>
    </xsl:variable>
    <xsl:variable name="ena">
      <xsl:value-of select="@enabled"/>
    </xsl:variable>
    <!-- The foreach's body is protected by this, so that we are actually
         going to iterate once per reduction rule, and not per lookahead. -->
    <xsl:if test='not(preceding-sibling::*[@rule=$rul and @enabled=$ena])'>
      <xsl:variable name="rule">
        <xsl:choose>
          <!-- The acceptation state is refered to as 'accept' in the XML, but
               just as '0' in the DOT. -->
          <xsl:when test="@rule='accept'">
            <xsl:text>0</xsl:text>
          </xsl:when>
          <xsl:otherwise>
            <xsl:value-of select="@rule"/>
          </xsl:otherwise>
        </xsl:choose>
      </xsl:variable>

      <!-- The edge's beginning -->
      <xsl:call-template name="reduction-edge-start">
        <xsl:with-param name="state" select="$staten"/>
        <xsl:with-param name="rule" select="$rule"/>
        <xsl:with-param name="enabled" select="@enabled"/>
      </xsl:call-template>

      <!-- The edge's tokens -->
      <!-- Don't show labels for the default action. In other cases, there will
           always be at least one token, so 'label="[]"' will not occur. -->
      <xsl:if test='$rule!=0 and not(../reduction[@enabled=$ena and @rule=$rule and @symbol="$default"])'>
        <xsl:text>label="[</xsl:text>
        <xsl:for-each select='../reduction[@enabled=$ena and @rule=$rule]'>
          <xsl:call-template name="escape">
            <xsl:with-param name="subject" select="@symbol"/>
          </xsl:call-template>
          <xsl:if test="position() != last ()">
            <xsl:text>, </xsl:text>
          </xsl:if>
        </xsl:for-each>
        <xsl:text>]", </xsl:text>
      </xsl:if>

      <!-- The edge's end -->
      <xsl:text>style=solid]&#10;</xsl:text>

      <!-- The diamond representing the reduction -->
      <xsl:call-template name="reduction-node">
        <xsl:with-param name="state" select="$staten"/>
        <xsl:with-param name="rule" select="$rule"/>
        <xsl:with-param name="color">
          <xsl:choose>
            <xsl:when test='@enabled="true"'>
              <xsl:text>3</xsl:text>
            </xsl:when>
            <xsl:otherwise>
              <xsl:text>5</xsl:text>
            </xsl:otherwise>
          </xsl:choose>
        </xsl:with-param>
      </xsl:call-template>
    </xsl:if>
  </xsl:for-each>
</xsl:template>

<xsl:template match="actions/transitions">
  <xsl:apply-templates select="transition"/>
</xsl:template>

<xsl:template match="item">
  <xsl:param name="prev-rule-number"
    select="preceding-sibling::item[1]/@rule-number"/>
  <xsl:apply-templates select="key('bison:ruleByNumber', @rule-number)">
    <xsl:with-param name="point" select="@point"/>
    <xsl:with-param name="num" select="@rule-number"/>
    <xsl:with-param name="prev-lhs"
      select="key('bison:ruleByNumber', $prev-rule-number)/lhs[text()]"
   />
  </xsl:apply-templates>
  <xsl:apply-templates select="lookaheads"/>
</xsl:template>

<xsl:template match="rule">
  <xsl:param name="point"/>
  <xsl:param name="num"/>
  <xsl:param name="prev-lhs"/>
  <xsl:text>&#10;</xsl:text>
  <xsl:choose>
    <xsl:when test="$num &lt; 10">
      <xsl:text>  </xsl:text>
    </xsl:when>
    <xsl:when test="$num &lt; 100">
      <xsl:text> </xsl:text>
    </xsl:when>
    <xsl:otherwise>
      <xsl:text></xsl:text>
    </xsl:otherwise>
  </xsl:choose>
  <xsl:value-of select="$num"/>
  <xsl:text> </xsl:text>
  <xsl:choose>
  <xsl:when test="$prev-lhs = lhs[text()]">
      <xsl:call-template name="lpad">
        <xsl:with-param name="str" select="'|'"/>
        <xsl:with-param name="pad" select="number(string-length(lhs[text()])) + 1"/>
      </xsl:call-template>
    </xsl:when>
    <xsl:otherwise>
      <xsl:value-of select="lhs"/>
      <xsl:text>:</xsl:text>
    </xsl:otherwise>
  </xsl:choose>
  <xsl:if test="$point = 0">
    <xsl:text> .</xsl:text>
  </xsl:if>

  <!-- RHS -->
  <xsl:for-each select="rhs/symbol|rhs/empty">
    <xsl:apply-templates select="."/>
    <xsl:if test="$point = position()">
      <xsl:text> .</xsl:text>
    </xsl:if>
  </xsl:for-each>
</xsl:template>

<xsl:template match="symbol">
  <xsl:text> </xsl:text>
  <xsl:value-of select="."/>
</xsl:template>

<xsl:template match="empty">
  <xsl:text> %empty</xsl:text>
</xsl:template>

<xsl:template match="lookaheads">
  <xsl:text>  [</xsl:text>
  <xsl:apply-templates select="symbol"/>
  <xsl:text>]</xsl:text>
</xsl:template>

<xsl:template match="lookaheads/symbol">
  <xsl:value-of select="."/>
  <xsl:if test="position() != last()">
    <xsl:text>, </xsl:text>
  </xsl:if>
</xsl:template>

<xsl:template name="reduction-edge-start">
  <xsl:param name="state"/>
  <xsl:param name="rule"/>
  <xsl:param name="enabled"/>

  <xsl:text>  </xsl:text>
  <xsl:value-of select="$state"/>
  <xsl:text> -> "</xsl:text>
  <xsl:value-of select="$state"/>
  <xsl:text>R</xsl:text>
  <xsl:value-of select="$rule"/>
  <xsl:if test='$enabled = "false"'>
    <xsl:text>d</xsl:text>
  </xsl:if>
  <xsl:text>" [</xsl:text>
</xsl:template>

<xsl:template name="reduction-node">
  <xsl:param name="state"/>
  <xsl:param name="rule"/>
  <xsl:param name="color"/>

  <xsl:text> "</xsl:text>
  <xsl:value-of select="$state"/>
  <xsl:text>R</xsl:text>
  <xsl:value-of select="$rule"/>
  <xsl:if test="$color = 5">
    <xsl:text>d</xsl:text>
  </xsl:if>
  <xsl:text>" [label="</xsl:text>
  <xsl:choose>
  <xsl:when test="$rule = 0">
    <xsl:text>Acc", fillcolor=1</xsl:text>
  </xsl:when>
  <xsl:otherwise>
    <xsl:text>R</xsl:text>
    <xsl:value-of select="$rule"/>
    <xsl:text>", fillcolor=</xsl:text>
    <xsl:value-of select="$color"/>
  </xsl:otherwise>
  </xsl:choose>
  <xsl:text>, shape=diamond, style=filled]&#10;</xsl:text>
</xsl:template>

<xsl:template match="transition">
  <xsl:call-template name="output-edge">
    <xsl:with-param name="src" select="../../../@number"/>
    <xsl:with-param name="dst" select="@state"/>
    <xsl:with-param name="style">
      <xsl:choose>
        <xsl:when test="@symbol = 'error'">
          <xsl:text>dotted</xsl:text>
        </xsl:when>
        <xsl:when test="@type = 'shift'">
          <xsl:text>solid</xsl:text>
        </xsl:when>
        <xsl:otherwise>
          <xsl:text>dashed</xsl:text>
        </xsl:otherwise>
      </xsl:choose>
    </xsl:with-param>
    <xsl:with-param name="label">
      <xsl:if test="not(@symbol = 'error')">
        <xsl:value-of select="@symbol"/>
      </xsl:if>
    </xsl:with-param>
  </xsl:call-template>
</xsl:template>

<xsl:template name="output-node">
  <xsl:param name="number"/>
  <xsl:param name="label"/>
  <xsl:text>  </xsl:text>
  <xsl:value-of select="$number"/>
  <xsl:text> [label="</xsl:text>
  <xsl:text>State </xsl:text>
  <xsl:value-of select="$number"/>
  <xsl:text>\n</xsl:text>
  <xsl:call-template name="escape">
    <xsl:with-param name="subject" select="$label"/>
  </xsl:call-template>
  <xsl:text>\l"]&#10;</xsl:text>
</xsl:template>

<xsl:template name="output-edge">
  <xsl:param name="src"/>
  <xsl:param name="dst"/>
  <xsl:param name="style"/>
  <xsl:param name="label"/>
  <xsl:text>  </xsl:text>
  <xsl:value-of select="$src"/>
  <xsl:text> -> </xsl:text>
  <xsl:value-of select="$dst"/>
  <xsl:text> [style=</xsl:text>
  <xsl:value-of select="$style"/>
  <xsl:if test="$label and $label != ''">
    <xsl:text> label="</xsl:text>
    <xsl:call-template name="escape">
      <xsl:with-param name="subject" select="$label"/>
    </xsl:call-template>
    <xsl:text>"</xsl:text>
  </xsl:if>
  <xsl:text>]&#10;</xsl:text>
</xsl:template>

<xsl:template name="escape">
  <xsl:param name="subject"/> <!-- required -->
  <xsl:call-template name="string-replace">
    <xsl:with-param name="subject">
      <xsl:call-template name="string-replace">
        <xsl:with-param name="subject">
          <xsl:call-template name="string-replace">
            <xsl:with-param name="subject" select="$subject"/>
            <xsl:with-param name="search" select="'\'"/>
            <xsl:with-param name="replace" select="'\\'"/>
          </xsl:call-template>
        </xsl:with-param>
        <xsl:with-param name="search" select="'&quot;'"/>
        <xsl:with-param name="replace" select="'\&quot;'"/>
      </xsl:call-template>
    </xsl:with-param>
    <xsl:with-param name="search" select="'&#10;'"/>
    <xsl:with-param name="replace" select="'\l'"/>
  </xsl:call-template>
</xsl:template>

<xsl:template name="string-replace">
  <xsl:param name="subject"/>
  <xsl:param name="search"/>
  <xsl:param name="replace"/>
  <xsl:choose>
    <xsl:when test="contains($subject, $search)">
      <xsl:variable name="before" select="substring-before($subject, $search)"/>
      <xsl:variable name="after" select="substring-after($subject, $search)"/>
      <xsl:value-of select="$before"/>
      <xsl:value-of select="$replace"/>
      <xsl:call-template name="string-replace">
        <xsl:with-param name="subject" select="$after"/>
        <xsl:with-param name="search" select="$search"/>
        <xsl:with-param name="replace" select="$replace"/>
      </xsl:call-template>
    </xsl:when>
    <xsl:otherwise>
      <xsl:value-of select="$subject"/>
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>

<xsl:template name="lpad">
  <xsl:param name="str" select="''"/>
  <xsl:param name="pad" select="0"/>
  <xsl:variable name="diff" select="$pad - string-length($str)" />
  <xsl:choose>
    <xsl:when test="$diff &lt; 0">
      <xsl:value-of select="$str"/>
    </xsl:when>
    <xsl:otherwise>
      <xsl:call-template name="space">
        <xsl:with-param name="repeat" select="$diff"/>
      </xsl:call-template>
      <xsl:value-of select="$str"/>
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>

</xsl:stylesheet>
