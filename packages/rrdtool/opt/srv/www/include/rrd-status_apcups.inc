# $Id$
# Do not edit! This file is automaticly generated by rrd-graph.xsl

apcups_charge_graph ()
{
    last_x="$1"
    if [ -f $rrd_dbpath/apcups/charge.rrd ]
    then
        max_label=$(printf "%-11.11s" "${_MN_rrd_max}")
        avg_label=$(printf "%-11.11s" "${_MN_rrd_avg}")
        min_label=$(printf "%-11.11s" "${_MN_rrd_min}")
        last_label=$(printf "%-11.11s" "${_MN_rrd_last}")
        update_label=$(printf "%-15.15s" "${_MN_rrd_update}")
        var1_label=$(printf "%-15.15s" "${_RRD3_RC_BATTERY}")
        /usr/bin/rrdtool graph /srv/www/img/rrd/apcups-charge-$last_x.png --title "APC-UPS ${_RRD3_RT_CHARGE} - $last_x" \
            --imginfo '<IMG SRC="/img/rrd/%s" WIDTH="%lu" HEIGHT="%lu" ALT="APC-UPS ${_RRD3_RT_CHARGE}">' \
            $rrd_width $rrd_height $rrd_common_opts --watermark "$rrd_watermark" \
            --end now --start end-${last_x} \
            --vertical-label "${_RRD3_RL_CHARGE}" \
            --font "WATERMARK:8" \
            $rrd_grid_background \
            DEF:var1=${rrd_dbpath}/apcups/charge.rrd:value:AVERAGE \
            VDEF:var1_max=var1,MAXIMUM \
            VDEF:var1_avg=var1,AVERAGE \
            VDEF:var1_min=var1,MINIMUM \
            VDEF:var1_last=var1,LAST \
            COMMENT:"\t\t\t\g" \
            COMMENT:"${max_label}\t\g" \
            COMMENT:"${avg_label}\t\g" \
            COMMENT:"${min_label}\t\g" \
            COMMENT:"${last_label}\l" \
            LINE1:var1#009900:"${var1_label}\t\g" \
            GPRINT:var1_max:"%.1lf\t\t\g" \
            GPRINT:var1_avg:"%.1lf\t\t\g" \
            GPRINT:var1_min:"%.1lf\t\t\g" \
            GPRINT:var1_last:"%.1lf\l" \
            COMMENT:"\n" \
            COMMENT:"${update_label}\t${rrd_last_update}"
    else
        show_error "$_MN_err" "no rrd-database for APC-UPS ${_RRD3_RT_CHARGE}"
    fi
}

apcups_frequency_graph ()
{
    last_x="$1"
    if [ -f $rrd_dbpath/apcups/frequency-input.rrd ]
    then
        ds_name=`rrdtool info $rrd_dbpath/apcups/frequency-input.rrd |grep -e "^ds.*type" | cut -d "[" -f2 | cut -d "]" -f1`
        max_label=$(printf "%-11.11s" "${_MN_rrd_max}")
        avg_label=$(printf "%-11.11s" "${_MN_rrd_avg}")
        min_label=$(printf "%-11.11s" "${_MN_rrd_min}")
        last_label=$(printf "%-11.11s" "${_MN_rrd_last}")
        update_label=$(printf "%-15.15s" "${_MN_rrd_update}")
        var1_label=$(printf "%-15.15s" "${_RRD3_RC_INPUT}")
        /usr/bin/rrdtool graph /srv/www/img/rrd/apcups-frequency-$last_x.png --title "APC-UPS ${_RRD3_RT_FREQUENCY} - $last_x" \
            --imginfo '<IMG SRC="/img/rrd/%s" WIDTH="%lu" HEIGHT="%lu" ALT="APC-UPS ${_RRD3_RT_FREQUENCY}">' \
            $rrd_width $rrd_height $rrd_common_opts --watermark "$rrd_watermark" \
            --end now --start end-${last_x} \
            --vertical-label "${_RRD3_RL_FREQUENCY}" \
            --font "WATERMARK:8" \
            $rrd_grid_background \
            DEF:var1=${rrd_dbpath}/apcups/frequency-input.rrd:${ds_name}:AVERAGE \
            VDEF:var1_max=var1,MAXIMUM \
            VDEF:var1_avg=var1,AVERAGE \
            VDEF:var1_min=var1,MINIMUM \
            VDEF:var1_last=var1,LAST \
            COMMENT:"\t\t\t\g" \
            COMMENT:"${max_label}\t\g" \
            COMMENT:"${avg_label}\t\g" \
            COMMENT:"${min_label}\t\g" \
            COMMENT:"${last_label}\l" \
            LINE1:var1#009900:"${var1_label}\t\g" \
            GPRINT:var1_max:"%.2lf\t\t\g" \
            GPRINT:var1_avg:"%.2lf\t\t\g" \
            GPRINT:var1_min:"%.2lf\t\t\g" \
            GPRINT:var1_last:"%.2lf\l" \
            COMMENT:"\n" \
            COMMENT:"${update_label}\t${rrd_last_update}"
    else
        show_error "$_MN_err" "no rrd-database for APC-UPS ${_RRD3_RT_FREQUENCY}"
    fi
}

apcups_load_graph ()
{
    last_x="$1"
    if [ -f $rrd_dbpath/apcups/percent-load.rrd ]
    then
        ds_name=`rrdtool info $rrd_dbpath/apcups/percent-load.rrd |grep -e "^ds.*type" | cut -d "[" -f2 | cut -d "]" -f1`
        max_label=$(printf "%-11.11s" "${_MN_rrd_max}")
        avg_label=$(printf "%-11.11s" "${_MN_rrd_avg}")
        min_label=$(printf "%-11.11s" "${_MN_rrd_min}")
        last_label=$(printf "%-11.11s" "${_MN_rrd_last}")
        update_label=$(printf "%-15.15s" "${_MN_rrd_update}")
        var1_label=$(printf "%-15.15s" "${_RRD3_RC_OUTPUT}")
        /usr/bin/rrdtool graph /srv/www/img/rrd/apcups-load-$last_x.png --title "APC-UPS ${_RRD3_RT_LOAD} - $last_x" \
            --imginfo '<IMG SRC="/img/rrd/%s" WIDTH="%lu" HEIGHT="%lu" ALT="APC-UPS ${_RRD3_RT_LOAD}">' \
            $rrd_width $rrd_height $rrd_common_opts --watermark "$rrd_watermark" \
            --end now --start end-${last_x} \
            --vertical-label "${_RRD3_RL_LOAD}" \
            --font "WATERMARK:8" \
            $rrd_grid_background \
            DEF:var1=${rrd_dbpath}/apcups/percent-load.rrd:${ds_name}:AVERAGE \
            VDEF:var1_max=var1,MAXIMUM \
            VDEF:var1_avg=var1,AVERAGE \
            VDEF:var1_min=var1,MINIMUM \
            VDEF:var1_last=var1,LAST \
            COMMENT:"\t\t\t\g" \
            COMMENT:"${max_label}\t\g" \
            COMMENT:"${avg_label}\t\g" \
            COMMENT:"${min_label}\t\g" \
            COMMENT:"${last_label}\l" \
            LINE1:var1#FF0000:"${var1_label}\t\g" \
            GPRINT:var1_max:"%.1lf\t\t\g" \
            GPRINT:var1_avg:"%.1lf\t\t\g" \
            GPRINT:var1_min:"%.1lf\t\t\g" \
            GPRINT:var1_last:"%.1lf\l" \
            COMMENT:"\n" \
            COMMENT:"${update_label}\t${rrd_last_update}"
    else
        show_error "$_MN_err" "no rrd-database for APC-UPS ${_RRD3_RT_LOAD}"
    fi
}

apcups_temperature_graph ()
{
    last_x="$1"
    if [ -f $rrd_dbpath/apcups/temperature.rrd ]
    then
        max_label=$(printf "%-11.11s" "${_MN_rrd_max}")
        avg_label=$(printf "%-11.11s" "${_MN_rrd_avg}")
        min_label=$(printf "%-11.11s" "${_MN_rrd_min}")
        last_label=$(printf "%-11.11s" "${_MN_rrd_last}")
        update_label=$(printf "%-15.15s" "${_MN_rrd_update}")
        var1_label=$(printf "%-15.15s" "${_RRD3_RC_INTERNAL}")
        /usr/bin/rrdtool graph /srv/www/img/rrd/apcups-temperature-$last_x.png --title "APC-UPS ${_RRD3_RT_TEMPERATUE} - $last_x" \
            --imginfo '<IMG SRC="/img/rrd/%s" WIDTH="%lu" HEIGHT="%lu" ALT="APC-UPS ${_RRD3_RT_TEMPERATUE}">' \
            $rrd_width $rrd_height $rrd_common_opts --watermark "$rrd_watermark" \
            --end now --start end-${last_x} \
            --vertical-label "${_RRD3_RL_TEMPERATUE}" \
            --font "WATERMARK:8" \
            $rrd_grid_background \
            DEF:var1=${rrd_dbpath}/apcups/temperature.rrd:value:AVERAGE \
            VDEF:var1_max=var1,MAXIMUM \
            VDEF:var1_avg=var1,AVERAGE \
            VDEF:var1_min=var1,MINIMUM \
            VDEF:var1_last=var1,LAST \
            COMMENT:"\t\t\t\g" \
            COMMENT:"${max_label}\t\g" \
            COMMENT:"${avg_label}\t\g" \
            COMMENT:"${min_label}\t\g" \
            COMMENT:"${last_label}\l" \
            LINE1:var1#009900:"${var1_label}\t\g" \
            GPRINT:var1_max:"%.1lf\t\t\g" \
            GPRINT:var1_avg:"%.1lf\t\t\g" \
            GPRINT:var1_min:"%.1lf\t\t\g" \
            GPRINT:var1_last:"%.1lf\l" \
            COMMENT:"\n" \
            COMMENT:"${update_label}\t${rrd_last_update}"
    else
        show_error "$_MN_err" "no rrd-database for APC-UPS ${_RRD3_RT_TEMPERATUE}"
    fi
}

apcups_timeleft_graph ()
{
    last_x="$1"
    if [ -f $rrd_dbpath/apcups/timeleft.rrd ]
    then
        ds_name=`rrdtool info $rrd_dbpath/apcups/timeleft.rrd |grep -e "^ds.*type" | cut -d "[" -f2 | cut -d "]" -f1`
        max_label=$(printf "%-11.11s" "${_MN_rrd_max}")
        avg_label=$(printf "%-11.11s" "${_MN_rrd_avg}")
        min_label=$(printf "%-11.11s" "${_MN_rrd_min}")
        last_label=$(printf "%-11.11s" "${_MN_rrd_last}")
        update_label=$(printf "%-15.15s" "${_MN_rrd_update}")
        var1_label=$(printf "%-15.15s" "${_RRD3_RC_BATTERY}")
        /usr/bin/rrdtool graph /srv/www/img/rrd/apcups-timeleft-$last_x.png --title "APC-UPS ${_RRD3_RT_TIMELEFT} - $last_x" \
            --imginfo '<IMG SRC="/img/rrd/%s" WIDTH="%lu" HEIGHT="%lu" ALT="APC-UPS ${_RRD3_RT_TIMELEFT}">' \
            $rrd_width $rrd_height $rrd_common_opts --watermark "$rrd_watermark" \
            --end now --start end-${last_x} \
            --vertical-label "${_RRD3_RL_TIMELEFT}" \
            --font "WATERMARK:8" \
            $rrd_grid_background \
            DEF:var1=${rrd_dbpath}/apcups/timeleft.rrd:${ds_name}:AVERAGE \
            VDEF:var1_max=var1,MAXIMUM \
            VDEF:var1_avg=var1,AVERAGE \
            VDEF:var1_min=var1,MINIMUM \
            VDEF:var1_last=var1,LAST \
            COMMENT:"\t\t\t\g" \
            COMMENT:"${max_label}\t\g" \
            COMMENT:"${avg_label}\t\g" \
            COMMENT:"${min_label}\t\g" \
            COMMENT:"${last_label}\l" \
            LINE1:var1#009900:"${var1_label}\t\g" \
            GPRINT:var1_max:"%.1lf\t\t\g" \
            GPRINT:var1_avg:"%.1lf\t\t\g" \
            GPRINT:var1_min:"%.1lf\t\t\g" \
            GPRINT:var1_last:"%.1lf\l" \
            COMMENT:"\n" \
            COMMENT:"${update_label}\t${rrd_last_update}"
    else
        show_error "$_MN_err" "no rrd-database for APC-UPS ${_RRD3_RT_TIMELEFT}"
    fi
}

apcups_batvolt_graph ()
{
    last_x="$1"
    if [ -f $rrd_dbpath/apcups/voltage-battery.rrd ]
    then
        max_label=$(printf "%-11.11s" "${_MN_rrd_max}")
        avg_label=$(printf "%-11.11s" "${_MN_rrd_avg}")
        min_label=$(printf "%-11.11s" "${_MN_rrd_min}")
        last_label=$(printf "%-11.11s" "${_MN_rrd_last}")
        update_label=$(printf "%-15.15s" "${_MN_rrd_update}")
        var1_label=$(printf "%-15.15s" "${_RRD3_RC_BATTERY}")
        /usr/bin/rrdtool graph /srv/www/img/rrd/apcups-batvolt-$last_x.png --title "APC-UPS ${_RRD3_RT_BATVOLT} - $last_x" \
            --imginfo '<IMG SRC="/img/rrd/%s" WIDTH="%lu" HEIGHT="%lu" ALT="APC-UPS ${_RRD3_RT_BATVOLT}">' \
            $rrd_width $rrd_height $rrd_common_opts --watermark "$rrd_watermark" \
            --end now --start end-${last_x} \
            --vertical-label "${_RRD3_RL_VOLT}" \
            --font "WATERMARK:8" \
            $rrd_grid_background \
            DEF:var1=${rrd_dbpath}/apcups/voltage-battery.rrd:value:AVERAGE \
            VDEF:var1_max=var1,MAXIMUM \
            VDEF:var1_avg=var1,AVERAGE \
            VDEF:var1_min=var1,MINIMUM \
            VDEF:var1_last=var1,LAST \
            COMMENT:"\t\t\t\g" \
            COMMENT:"${max_label}\t\g" \
            COMMENT:"${avg_label}\t\g" \
            COMMENT:"${min_label}\t\g" \
            COMMENT:"${last_label}\l" \
            LINE1:var1#009900:"${var1_label}\t\g" \
            GPRINT:var1_max:"%.2lf\t\t\g" \
            GPRINT:var1_avg:"%.2lf\t\t\g" \
            GPRINT:var1_min:"%.2lf\t\t\g" \
            GPRINT:var1_last:"%.2lf\l" \
            COMMENT:"\n" \
            COMMENT:"${update_label}\t${rrd_last_update}"
    else
        show_error "$_MN_err" "no rrd-database for APC-UPS ${_RRD3_RT_BATVOLT}"
    fi
}

apcups_pwrvolt_graph ()
{
    last_x="$1"
    if [ -f $rrd_dbpath/apcups/voltage-input.rrd -a \
         -f $rrd_dbpath/apcups/voltage-output.rrd ]
    then
        max_label=$(printf "%-11.11s" "${_MN_rrd_max}")
        avg_label=$(printf "%-11.11s" "${_MN_rrd_avg}")
        min_label=$(printf "%-11.11s" "${_MN_rrd_min}")
        last_label=$(printf "%-11.11s" "${_MN_rrd_last}")
        update_label=$(printf "%-15.15s" "${_MN_rrd_update}")
        var1_label=$(printf "%-15.15s" "${_RRD3_RC_INPUT}")
        var2_label=$(printf "%-15.15s" "${_RRD3_RC_OUTPUT}")
        /usr/bin/rrdtool graph /srv/www/img/rrd/apcups-pwrvolt-$last_x.png --title "APC-UPS ${_RRD3_RT_PWRVOLT} - $last_x" \
            --imginfo '<IMG SRC="/img/rrd/%s" WIDTH="%lu" HEIGHT="%lu" ALT="APC-UPS ${_RRD3_RT_PWRVOLT}">' \
            $rrd_width $rrd_height $rrd_common_opts --watermark "$rrd_watermark" \
            --end now --start end-${last_x} \
            --vertical-label "${_RRD3_RL_VOLT}" \
            --font "WATERMARK:8" \
            $rrd_grid_background \
            DEF:var1=${rrd_dbpath}/apcups/voltage-input.rrd:value:AVERAGE \
            DEF:var2=${rrd_dbpath}/apcups/voltage-output.rrd:value:AVERAGE \
            CDEF:var2_d=var2,0.2,+ \
            VDEF:var1_max=var1,MAXIMUM \
            VDEF:var1_avg=var1,AVERAGE \
            VDEF:var1_min=var1,MINIMUM \
            VDEF:var1_last=var1,LAST \
            VDEF:var2_max=var2,MAXIMUM \
            VDEF:var2_avg=var2,AVERAGE \
            VDEF:var2_min=var2,MINIMUM \
            VDEF:var2_last=var2,LAST \
            COMMENT:"\t\t\t\g" \
            COMMENT:"${max_label}\t\g" \
            COMMENT:"${avg_label}\t\g" \
            COMMENT:"${min_label}\t\g" \
            COMMENT:"${last_label}\l" \
            LINE1:var1#009900:"${var1_label}\t\g" \
            GPRINT:var1_max:"%.1lf\t\t\g" \
            GPRINT:var1_avg:"%.1lf\t\t\g" \
            GPRINT:var1_min:"%.1lf\t\t\g" \
            GPRINT:var1_last:"%.1lf\l" \
            LINE1:var2_d#FF0000:"${var2_label}\t\g" \
            GPRINT:var2_max:"%.1lf\t\t\g" \
            GPRINT:var2_avg:"%.1lf\t\t\g" \
            GPRINT:var2_min:"%.1lf\t\t\g" \
            GPRINT:var2_last:"%.1lf\l" \
            COMMENT:"\n" \
            COMMENT:"${update_label}\t${rrd_last_update}"
    else
        show_error "$_MN_err" "no rrd-database for APC-UPS ${_RRD3_RT_PWRVOLT}"
    fi
}

# _oOo_
