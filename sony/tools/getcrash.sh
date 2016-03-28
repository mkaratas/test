author="Jianzhong Cui"
version="1.0.0"
date=`date`

top=`pwd`
core_pdf_dir=$top/crash_workdir
core_pdf_file=$core_pdf_dir/vmcore.pdf
goobug_url="http://goobug.sonyericsson.net"

function infomation()
{
	echo "=========================== INFOMATION ===================================="
	echo -e "Script Author: \033[35m$author\033[0m"
	echo -e "Date         : \033[35m$date\033[0m"
	echo -e "Version      : \033[35m$version\033[0m"
	DMS_NUM=$(pwd | awk -F"/" '{for(f=1; f <= NF; f+=1) {if ($f ~ /DMS/){print $f}}}')
	echo -e "DMS number   : \033[35m$DMS_NUM\033[0m"
	echo "==========================================================================="
}

function get_crash_file()
{
	echo -e "\033[34mGetting crash files from $goobug_url ...\033[0m"
	debuggy --crash tlcore
}

function generate_report_pdf()
{
	echo -e "\033[34mGenerating crash report pdf file...\033[0m"
	debuggy --crashpdf tlcore
}

function change_pdf_file_name()
{
	if [ -f $core_pdf_file ]; then
		mv $core_pdf_file $core_pdf_dir/$DMS_NUM.pdf
	else
		echo -e "\033[31mError: file $core_pdf_file does not exist.\033[0m"	
	fi
}

infomation;
get_crash_file;
generate_report_pdf;
change_pdf_file_name;
echo -e "\033[32mDone\033[0m"
