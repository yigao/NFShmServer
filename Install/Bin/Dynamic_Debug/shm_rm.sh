#!/bin/bash

user=$2
if [ "$user" == "" ];then
    user=$USER
fi

SEMID=`ipcs -m | grep $user | awk '{ if ($6==0) print $2 }'`
for ID in $SEMID
do
    ipcrm -m $ID&&echo shm cleared:$ID
done


#ipcs -m | awk '{if($6==0)print $2}' | xargs ipcrm shm

