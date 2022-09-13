
USR="root"
PASSWRD="root"
DBNAME="proto_ff"

MYSQL=mysql

mysqldump -u${USR} -p${PASSWRD} ${DBNAME} > ${DBNAME}.sql
mysql -u${USR} -p${PASSWRD} -e "drop database proto_ff"
mysql -u${USR} -p${PASSWRD} -e "create database proto_ff"

TABLE_LIST="tbAccountTable  tbUserDetailData tbUserSimpleData tbEventLog ConstDesc NameDesc"

for table in ${TABLE_LIST}
do
    SQL=create_${table}.sql
    ${MYSQL}  -u${USR} -p${PASSWRD} ${DBNAME} < ${SQL}
done
