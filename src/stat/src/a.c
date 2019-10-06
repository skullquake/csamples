#include<stdio.h>
#include<json-c/json.h>
#include<unistd.h>             // fstat
#include<fcntl.h>              // fstat
#include<stdio.h>              // fstat
#include<sys/stat.h>           // fstat
#include<sys/types.h>          // fstat
json_object* stat2json(struct stat fileStat){
	json_object* jobjStat=json_object_new_object();
	json_object_object_add(
		jobjStat,
		"st_size",
		json_object_new_int(
			fileStat.st_size
		)
	);
	json_object_object_add(
		jobjStat,
		"st_nlink",
		json_object_new_int(
			fileStat.st_nlink
		)
	);
	json_object_object_add(
		jobjStat,
		"st_ino",
		json_object_new_int(
			fileStat.st_ino
		)
	);
	char strperm[11];
	sprintf(strperm+0,(S_ISDIR(fileStat.st_mode)) ? "d" : "-");
	sprintf(strperm+1, (fileStat.st_mode & S_IRUSR) ? "r" : "-");
	sprintf(strperm+2, (fileStat.st_mode & S_IWUSR) ? "w" : "-");
	sprintf(strperm+3, (fileStat.st_mode & S_IXUSR) ? "x" : "-");
	sprintf(strperm+4, (fileStat.st_mode & S_IRGRP) ? "r" : "-");
	sprintf(strperm+5, (fileStat.st_mode & S_IWGRP) ? "w" : "-");
	sprintf(strperm+6, (fileStat.st_mode & S_IXGRP) ? "x" : "-");
	sprintf(strperm+7, (fileStat.st_mode & S_IROTH) ? "r" : "-");
	sprintf(strperm+8, (fileStat.st_mode & S_IWOTH) ? "w" : "-");
	sprintf(strperm+9, (fileStat.st_mode & S_IXOTH) ? "x" : "-");
	json_object_object_add(
		jobjStat,
		"st_mode ",
		json_object_new_string(
			strperm
		)
	);
	json_object_object_add(
		jobjStat,
		"S_ISLNK",
		json_object_new_boolean(
			 (S_ISLNK(fileStat.st_mode)) ? TRUE:FALSE
		)
	);
	return jobjStat;

}
int main(int argc,char** argv){
	struct stat fileStat;
	json_object* jobjStat;
	jobjStat=NULL;
	if(stat("./src/a.c",&fileStat)<0){
		jobjStat=json_object_new_object();
		json_object_object_add(
			jobjStat,
			"error",
			json_object_new_string(
				"Failed to stat file"
			)
		);
	}else{
		jobjStat=stat2json(fileStat);
	}
	printf(
		"%s\n",
		json_object_to_json_string_ext(
			jobjStat,
			JSON_C_TO_STRING_SPACED|JSON_C_TO_STRING_PRETTY
		)
	);
	return 0;
}
