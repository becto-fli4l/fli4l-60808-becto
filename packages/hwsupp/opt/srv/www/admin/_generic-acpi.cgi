#!/bin/sh
# $Id$
# Do not edit! This file is automaticly generated by rrd-cgi.xsl

. /srv/www/include/cgi-helper
# set_debug=yes

# Security
check_rights "hwsupp" "view"

# get some internal variables
. /var/run/hwsupp.conf

show_html_header "ACPI PC"

if [ -e /srv/www/include/rrd-common.inc ]
then
    . /srv/www/include/rrd-common.inc
    if [ -e /srv/www/include/rrd-generic-acpi.inc ]
    then
     . /srv/www/include/rrd-generic-acpi.inc
    fi
fi
if [ -e /srv/www/include/hwmon-generic-acpi.inc ]
then
    . /srv/www/include/hwmon-generic-acpi.inc
fi
if [ -e /srv/www/include/extra-cpufreq.inc ]
then
    . /srv/www/include/extra-cpufreq.inc
fi
if [ -e /srv/www/include/extra-dmidecode.inc ]
then
    . /srv/www/include/extra-dmidecode.inc
fi

: ${FORM_action:=generic_acpi_frequency}
if [ -e /srv/www/include/rrd-common.inc ]
then
    : ${FORM_rrd_graphtime_generic_acpi_frequency:=$rrd_default_graphtime}

    eval local rrd_source_time='$FORM_rrd_graphtime_'$rrd_source
    : ${rrd_source_time:=$rrd_default_graphtime}
fi
action_list=""
if [ -e /srv/www/include/rrd-common.inc ]
then
    action_list="$action_list frequency"
fi
action_list="$action_list hwmon"
if [ "$hwsupp_cpufreq" = "yes" ]
then
    action_list="$action_list cpufreq"
fi
action_list="$action_list bios"

tab_list=""
for i in ${action_list}
do
    case $i in
        frequency)
            label=$(translate_label "${_HWSUPP_FREQUENCY}")
        ;;
        hwmon)
            label=$(translate_label "${_HWSUPP_HWMON}")
        ;;
        cpufreq)
            label=$(translate_label "${_HWSUPP_CPUFREQ}")
        ;;
        bios)
            label=$(translate_label "${_HWSUPP_DMI}")
        ;;
    esac
    if [ "$FORM_action" = "generic_acpi_$i" ]
    then
        tab_list=`echo "$tab_list $label no"`
    else
        tab_list=`echo "$tab_list $label $myname?action=generic_acpi_$i"`
    fi
done

show_tab_header $tab_list
case $FORM_action in
    generic_acpi_hwmon)
        hwmon_generic_acpi
    ;;
    generic_acpi_cpufreq)
        extra_cpufreq
    ;;
    generic_acpi_bios)
        extra_dmidecode
    ;;
    *)
        rrd_open_tab_list $FORM_action
        rrd_render_graph $FORM_action
        rrd_close_tab_list
    ;;
esac

show_tab_footer

show_html_footer

# _oOo_