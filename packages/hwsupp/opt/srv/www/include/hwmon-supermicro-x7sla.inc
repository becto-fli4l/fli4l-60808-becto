# $Id$
# Do not edit! This file is automaticly generated by hwmon-inc.xsl

hwmon_supermicro_x7sla_temp ()
{
    var1=`sensors -u w83627dhg-isa-0290 | grep temp1_input | cut -d : -f 2`
    var1=`echo ${var1}| sed 's/[^0-9]*\([0-9]*\)\.\([0-9]\{1\}\).*/\1.\2/'`
    var2=`sensors -u w83627dhg-isa-0290 | grep temp2_input | cut -d : -f 2`
    var2=`echo ${var2}| sed 's/[^0-9]*\([0-9]*\)\.\([0-9]\{1\}\).*/\1.\2/'`

    show_tab_header ${_HWSUPP_RT_TEMP} no

    echo "<table class='normtable'>"
    echo "<tr>"
    echo "<th>${_HWSUPP_HWMON_SENSOR}</th>"
    echo "<th>${_HWSUPP_RL_TEMP}</th>"
    echo "</tr>"
    echo "<tr align='center'>"
    echo "<td>${_HWSUPP_RC_MB}</td>"
    echo "<td>${var1}</td>"
    echo "</tr>"
    echo "<tr align='center'>"
    echo "<td>${_HWSUPP_RC_CPU}</td>"
    echo "<td>${var2}</td>"
    echo "</tr>"
    echo "</table>"

    show_tab_footer
}

hwmon_supermicro_x7sla_voltage ()
{
    var1=`sensors -u w83627dhg-isa-0290 | grep in0_input | cut -d : -f 2`
    var1=`echo ${var1}| sed 's/[^0-9]*\([0-9]*\)\.\([0-9]\{3\}\).*/\1.\2/'`
    var2=`sensors -u w83627dhg-isa-0290 | grep in1_input | cut -d : -f 2`
    var2=`echo ${var2}| sed 's/[^0-9]*\([0-9]*\)\.\([0-9]\{3\}\).*/\1.\2/'`
    var3=`sensors -u w83627dhg-isa-0290 | grep in2_input | cut -d : -f 2`
    var3=`echo ${var3}| sed 's/[^0-9]*\([0-9]*\)\.\([0-9]\{3\}\).*/\1.\2/'`
    var4=`sensors -u w83627dhg-isa-0290 | grep in3_input | cut -d : -f 2`
    var4=`echo ${var4}| sed 's/[^0-9]*\([0-9]*\)\.\([0-9]\{3\}\).*/\1.\2/'`
    var5=`sensors -u w83627dhg-isa-0290 | grep in4_input | cut -d : -f 2`
    var5=`echo ${var5}| sed 's/[^0-9]*\([0-9]*\)\.\([0-9]\{3\}\).*/\1.\2/'`
    var6=`sensors -u w83627dhg-isa-0290 | grep in5_input | cut -d : -f 2`
    var6=`echo ${var6}| sed 's/[^0-9]*\([0-9]*\)\.\([0-9]\{3\}\).*/\1.\2/'`
    var7=`sensors -u w83627dhg-isa-0290 | grep in6_input | cut -d : -f 2`
    var7=`echo ${var7}| sed 's/[^0-9]*\([0-9]*\)\.\([0-9]\{3\}\).*/\1.\2/'`
    var8=`sensors -u w83627dhg-isa-0290 | grep in7_input | cut -d : -f 2`
    var8=`echo ${var8}| sed 's/[^0-9]*\([0-9]*\)\.\([0-9]\{3\}\).*/\1.\2/'`
    var9=`sensors -u w83627dhg-isa-0290 | grep in8_input | cut -d : -f 2`
    var9=`echo ${var9}| sed 's/[^0-9]*\([0-9]*\)\.\([0-9]\{3\}\).*/\1.\2/'`

    show_tab_header ${_HWSUPP_RT_VOLTAGE} no

    echo "<table class='normtable'>"
    echo "<tr>"
    echo "<th>${_HWSUPP_HWMON_SENSOR}</th>"
    echo "<th>${_HWSUPP_RL_VOLTAGE}</th>"
    echo "</tr>"
    echo "<tr align='center'>"
    echo "<td>${_HWSUPP_RC_VCORE}</td>"
    echo "<td>${var1}</td>"
    echo "</tr>"
    echo "<tr align='center'>"
    echo "<td>${_HWSUPP_RC_V12}</td>"
    echo "<td>${var2}</td>"
    echo "</tr>"
    echo "<tr align='center'>"
    echo "<td>${_HWSUPP_RC_V3_3}</td>"
    echo "<td>${var3}</td>"
    echo "</tr>"
    echo "<tr align='center'>"
    echo "<td>${_HWSUPP_RC_VCC}</td>"
    echo "<td>${var4}</td>"
    echo "</tr>"
    echo "<tr align='center'>"
    echo "<td>Vdimm</td>"
    echo "<td>${var5}</td>"
    echo "</tr>"
    echo "<tr align='center'>"
    echo "<td>${_HWSUPP_RC_V5}</td>"
    echo "<td>${var6}</td>"
    echo "</tr>"
    echo "<tr align='center'>"
    echo "<td>${_HWSUPP_RC_V1_5}</td>"
    echo "<td>${var7}</td>"
    echo "</tr>"
    echo "<tr align='center'>"
    echo "<td>${_HWSUPP_RC_V3SB}</td>"
    echo "<td>${var8}</td>"
    echo "</tr>"
    echo "<tr align='center'>"
    echo "<td>${_HWSUPP_RC_VBAT}</td>"
    echo "<td>${var9}</td>"
    echo "</tr>"
    echo "</table>"

    show_tab_footer
}

hwmon_supermicro_x7sla_fanspeed ()
{
    var1=`sensors -u w83627dhg-isa-0290 | grep fan1_input | cut -d : -f 2`
    var1=`echo ${var1}| sed 's/[^0-9]*\([0-9]*\).*/\1/'`
    var2=`sensors -u w83627dhg-isa-0290 | grep fan2_input | cut -d : -f 2`
    var2=`echo ${var2}| sed 's/[^0-9]*\([0-9]*\).*/\1/'`
    var3=`sensors -u w83627dhg-isa-0290 | grep fan5_input | cut -d : -f 2`
    var3=`echo ${var3}| sed 's/[^0-9]*\([0-9]*\).*/\1/'`
    var4=`sensors -u w83627dhg-isa-0290 | grep fan4_input | cut -d : -f 2`
    var4=`echo ${var4}| sed 's/[^0-9]*\([0-9]*\).*/\1/'`

    show_tab_header ${_HWSUPP_RT_FANSPEED} no

    echo "<table class='normtable'>"
    echo "<tr>"
    echo "<th>${_HWSUPP_HWMON_SENSOR}</th>"
    echo "<th>${_HWSUPP_RL_FANSPEED}</th>"
    echo "</tr>"
    echo "<tr align='center'>"
    echo "<td>${_HWSUPP_RC_BACK}</td>"
    echo "<td>${var1}</td>"
    echo "</tr>"
    echo "<tr align='center'>"
    echo "<td>${_HWSUPP_RC_PSU}</td>"
    echo "<td>${var2}</td>"
    echo "</tr>"
    echo "<tr align='center'>"
    echo "<td>${_HWSUPP_RC_FRONT}</td>"
    echo "<td>${var3}</td>"
    echo "</tr>"
    echo "<tr align='center'>"
    echo "<td>MCH</td>"
    echo "<td>${var4}</td>"
    echo "</tr>"
    echo "</table>"

    show_tab_footer
}

hwmon_supermicro_x7sla_frequency ()
{
    var1=`cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq`
    var1=$((var1 / 1000))

    show_tab_header ${_HWSUPP_RT_FREQUENCY} no

    echo "<table class='normtable'>"
    echo "<tr>"
    echo "<th>${_HWSUPP_HWMON_SENSOR}</th>"
    echo "<th>${_HWSUPP_RL_FREQUENCY}</th>"
    echo "</tr>"
    echo "<tr align='center'>"
    echo "<td>${_HWSUPP_RC_CPU} 0</td>"
    echo "<td>${var1}</td>"
    echo "</tr>"
    echo "</table>"

    show_tab_footer
}

hwmon_supermicro_x7sla ()
{
    hwmon_supermicro_x7sla_temp
    hwmon_supermicro_x7sla_voltage
    hwmon_supermicro_x7sla_fanspeed
    hwmon_supermicro_x7sla_frequency
}

# _oOo_
