set OutDir="..\src\NFComm\NFMessageDefine"
  
python ../tools/excel_2_bin/excel2bin_new.py --excel=../Excel/FishConfig.xls --proto_ds=%OutDir%/ResMeta.proto.ds --proto_package=proto_ff --proto_sheet_msgname=Sheet_FishConfigDesc --excel_sheetname=FishConfig --proto_msgname=FishConfigDesc --start_row=3 --out_path=../Install/Config/Data/

pause
