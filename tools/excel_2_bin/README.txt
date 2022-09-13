使用说明
1：编写excel的对应描述文件

导入依赖的文件
import "yd_fieldoptions.proto";

编写excel中sheet对应的message

每个message中的field必须要定义conv_def.cname这个options，该cname必须和excel中的列名完全一致

2：将描述文件生成pb的数据集文件
example：protoc --proto_path=./ --proto_path=/usr/local/include --proto_path=../../../field_options --include_imports --descriptor_set_out=test.proto.ds ./test.proto
--proto_path必须包括导入文件的全路径

3：生成最终的bin文件
使用脚本../excel2bin.py --excel=test.xls --proto_ds=./test.proto.ds --message_name=Charge
这里的message_name就是第一步中message的名字

可以用一个统一的脚本一步生成，例如
#!/bin/bash

protoc --proto_path=./ --proto_path=/usr/local/include --proto_path=../../../field_options --include_imports --descriptor_set_out=test.proto.ds ./test.proto
../excel2bin.py --excel=test.xls --proto_ds=./test.proto.ds --message_name=Charge