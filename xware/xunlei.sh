#!/bin/sh /etc/rc.common

idForVendor=`/usr/bin/matool --method idForVendor --params adaccf1f-8b8c-edcb-d533-770099d2ef20`
PIPE_PATH="/tmp/thunder/etm_hubble_report.pipe"

if [ -n "$idForVendor" ];then
	/usr/sbin/etm --system_path=/tmp/thunder --disk_cfg=/etc/config/thunder/thunder_mounts.cfg --etm_cfg=/etc/config/thunder/etm.ini --log_cfg=/etc/config/thunder/log.ini --deviceid=$idForVendor --hardwareid=$idForVendor --pid_file=/var/run/xunlei.pid --license=1504240001000004d000594b5jbn9whkghicubwoxw --import_v1v2_mode=2 --hubble_report_pipe_path=$PIPE_PATH
fi

