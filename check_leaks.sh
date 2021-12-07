# !/bin/bash
while true; do
	cub3d_pid=$(pgrep cub3d)
	if [ -n "$cub3d_pid" ]
	then
		leaks_result=$( leaks -q --list minishell ) 
		lsof_result=$( lsof -p $cub3d_pid )
		processes=$(ps)
		echo "                                 LEAKS CHECK"
		echo "$leaks_result"
		echo "                                 FD CHECK"
		echo "$lsof_result"
		echo "                                 PROCESSES"
		echo "$processes"
	fi
	sleep 3
	clear
done