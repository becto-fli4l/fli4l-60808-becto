# $Id$
# Do not edit! This file is automaticly generated by rrd-graph.xsl

pcengines_apu_temp_graph ()
{
    last_x="$1"
    if [ -f $rrd_dbpath/sensors-k10temp-pci-00c3/temperature-temp1.rrd ]
    then
        max_label=$(printf "%-11.11s" "${_MN_rrd_max}")
        avg_label=$(printf "%-11.11s" "${_MN_rrd_avg}")
        min_label=$(printf "%-11.11s" "${_MN_rrd_min}")
        last_label=$(printf "%-11.11s" "${_MN_rrd_last}")
        update_label=$(printf "%-15.15s" "${_MN_rrd_update}")
        var1_label=$(printf "%-15.15s" "${_HWSUPP_RC_CPU}")
        /usr/bin/rrdtool graph /srv/www/img/rrd/pcengines_apu-temp-$last_x.png --title "PC Engines APU ${_HWSUPP_RT_TEMP} - $last_x" \
            --imginfo '<IMG SRC="/img/rrd/%s" WIDTH="%lu" HEIGHT="%lu" ALT="PC Engines APU ${_HWSUPP_RT_TEMP}">' \
            $rrd_width $rrd_height $rrd_common_opts --watermark "$rrd_watermark" \
            --end now --start end-${last_x} \
            --vertical-label "${_HWSUPP_RL_TEMP}" \
            --font "WATERMARK:8" \
            $rrd_grid_background \
            DEF:var1=${rrd_dbpath}/sensors-k10temp-pci-00c3/temperature-temp1.rrd:value:AVERAGE \
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
        show_error "$_MN_err" "no rrd-database for PC Engines APU ${_HWSUPP_RT_TEMP}"
    fi
}

pcengines_apu_frequency_graph ()
{
    last_x="$1"
    if [ -f $rrd_dbpath/cpufreq/cpufreq-0.rrd -a \
         -f $rrd_dbpath/cpufreq/cpufreq-1.rrd ]
    then
        max_label=$(printf "%-11.11s" "${_MN_rrd_max}")
        avg_label=$(printf "%-11.11s" "${_MN_rrd_avg}")
        min_label=$(printf "%-11.11s" "${_MN_rrd_min}")
        last_label=$(printf "%-11.11s" "${_MN_rrd_last}")
        update_label=$(printf "%-15.15s" "${_MN_rrd_update}")
        var1_label=$(printf "%-15.15s" "${_HWSUPP_RC_CPU} 0")
        var2_label=$(printf "%-15.15s" "${_HWSUPP_RC_CPU} 1")
        /usr/bin/rrdtool graph /srv/www/img/rrd/pcengines_apu-frequency-$last_x.png --title "PC Engines APU ${_HWSUPP_RT_FREQUENCY} - $last_x" \
            --imginfo '<IMG SRC="/img/rrd/%s" WIDTH="%lu" HEIGHT="%lu" ALT="PC Engines APU ${_HWSUPP_RT_FREQUENCY}">' \
            $rrd_width $rrd_height $rrd_common_opts --watermark "$rrd_watermark" \
            --end now --start end-${last_x} \
            --vertical-label "${_HWSUPP_RL_FREQUENCY}" \
            --units-exponent 0 \
            --font "WATERMARK:8" \
            $rrd_grid_background \
            DEF:var1_1=${rrd_dbpath}/cpufreq/cpufreq-0.rrd:value:AVERAGE \
            DEF:var2_1=${rrd_dbpath}/cpufreq/cpufreq-1.rrd:value:AVERAGE \
            CDEF:var1=var1_1,1000000,/ \
            CDEF:var2=var2_1,1000000,/ \
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
            LINE1:var1#FF0000:"${var1_label}\t\g" \
            GPRINT:var1_max:"%.1lf\t\t\g" \
            GPRINT:var1_avg:"%.1lf\t\t\g" \
            GPRINT:var1_min:"%.1lf\t\t\g" \
            GPRINT:var1_last:"%.1lf\l" \
            LINE1:var2#00FF00:"${var2_label}\t\g" \
            GPRINT:var2_max:"%.1lf\t\t\g" \
            GPRINT:var2_avg:"%.1lf\t\t\g" \
            GPRINT:var2_min:"%.1lf\t\t\g" \
            GPRINT:var2_last:"%.1lf\l" \
            COMMENT:"\n" \
            COMMENT:"${update_label}\t${rrd_last_update}"
    else
        show_error "$_MN_err" "no rrd-database for PC Engines APU ${_HWSUPP_RT_FREQUENCY}"
    fi
}

# _oOo_
