#define FUSE_USE_VERSION 28
#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <pwd.h>
#include <sys/time.h>

static const char *dirpath = "/home/anwar/sisop/asiap";

static int xmp_utimens(const char *path, const struct timespec ts[2])
{
	int res;

char fpath[1000];
	if(strcmp(path,"/") == 0)
		{
			path=dirpath;
			sprintf(fpath,"%s",path);
		}
		else {

			char filename[999];
			char characterList[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
			int key = 17;

			strncpy(filename,path,99);
	
			if(strcmp(filename,"..") > 0 && strcmp(filename,".") > 0){
				for(int i=0; i<strlen(filename); i++){
					for(int j=0; j<strlen(characterList); j++){
						if(filename[i] == characterList[j]){
							int predictedCharAscii = j + key;
							if(predictedCharAscii > strlen(characterList) - 1){
								predictedCharAscii= predictedCharAscii - (strlen(characterList));
							}
							filename[i] = characterList[predictedCharAscii];
							break;
						}
								
					}
				}

			}

			sprintf(fpath, "%s%s",dirpath,filename);
		}

	struct timeval tv[2];

	tv[0].tv_sec = ts[0].tv_sec;
	tv[0].tv_usec = ts[0].tv_nsec / 1000;
	tv[1].tv_sec = ts[1].tv_sec;
	tv[1].tv_usec = ts[1].tv_nsec / 1000;

	//strcat(fpath,"`[S%");

	//printf("Touch : %s\n",fpath);
	res = utimes(fpath, tv);
	if (res == -1){
		printf("error utimens\n\n");
		return -errno;
	}

	printf("utimens\n\n");

	return 0;
}

static int xmp_create(const char* path, mode_t mode, struct fuse_file_info* fi) {

    (void) fi;

    int res = -1;
	char fpath[1000];
	char rules[999];
	pid_t child_id;        
	

	if(strcmp(path,"/") == 0)
	{
		path=dirpath;
		sprintf(fpath,"%s",path);
		strcpy(rules,fpath);
		strcat(rules,"`[S%");
	}
	else {
		char filename[999];
		char characterList[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
		int key = 17;

		strncpy(filename,path,99);
		
		if(strcmp(filename,"..") > 0 && strcmp(filename,".") > 0){
			for(int i=0; i<strlen(filename); i++){
				for(int j=0; j<strlen(characterList); j++){
					if(filename[i] == characterList[j]){
						int predictedCharAscii = j + key;
						if(predictedCharAscii > strlen(characterList) - 1){
							predictedCharAscii= predictedCharAscii - (strlen(characterList));
						}
						filename[i] = characterList[predictedCharAscii];
						break;
					}
								
				}
			}

		}

		sprintf(fpath, "%s%s",dirpath,filename);
		strcpy(rules,fpath);
		strcat(rules,"`[S%");
	}

		//strcat(fpath,"`[S%");

	printf("Touch : %s\n",rules);
    char ytPath[99];
	strncpy(ytPath,fpath,32);
	int flag=0;
	char *argv[4] = {"mv",fpath,rules,NULL};
    

    if (strcmp(ytPath,"/home/anwar/sisop/asiap/@ZA>AXio") == 0){
		mode = 0640;
	    res = creat(fpath, mode);
		flag=1;

    }

	printf("rules %s %s \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n",fpath,rules);

	/*if (flag){
		child_id = fork();
		if(child_id == 0)
			execvp("mv",argv);   
	}*/
	
	if(res == -1){
		printf("create\n\n");
		return -errno;
	}

	
    close(res);

	printf("create CREATECREAT\n\n\n\n\n\n\n\n");

	
    return 0;
}

static int xmp_unlink(const char *path)
{
	int res;

    char fpath[1000];
		if(strcmp(path,"/") == 0)
		{
			path=dirpath;
			sprintf(fpath,"%s",path);
		}
		else {

			char filename[999];
			char characterList[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
			int key = 17;

			strncpy(filename,path,99);
		//	char c[100];

			if(strcmp(filename,"..") > 0 && strcmp(filename,".") > 0){
				for(int i=0; i<strlen(filename); i++){
					for(int j=0; j<strlen(characterList); j++){
						if(filename[i] == characterList[j]){
							int predictedCharAscii = j + key;
							if(predictedCharAscii > strlen(characterList) - 1){
								predictedCharAscii= predictedCharAscii - (strlen(characterList));
							}
							filename[i] = characterList[predictedCharAscii];
							break;
						}
								
					}
				}

			//	strcat(c,filename);
			}

			sprintf(fpath, "%s%s",dirpath,filename);
		}

	res = unlink(fpath);
	if (res == -1)
		return -errno;

	return 0;
}

static int xmp_truncate(const char *path, off_t size)
{
    int res;

        char fpath[1000];
		if(strcmp(path,"/") == 0)
		{
			path=dirpath;
			sprintf(fpath,"%s",path);
		}
		else {

			char filename[999];
			char characterList[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
			int key = 17;

			strncpy(filename,path,99);
		//	char c[100];

			if(strcmp(filename,"..") > 0 && strcmp(filename,".") > 0){
				for(int i=0; i<strlen(filename); i++){
					for(int j=0; j<strlen(characterList); j++){
						if(filename[i] == characterList[j]){
							int predictedCharAscii = j + key;
							if(predictedCharAscii > strlen(characterList) - 1){
								predictedCharAscii= predictedCharAscii - (strlen(characterList));
							}
							filename[i] = characterList[predictedCharAscii];
							break;
						}
								
					}
				}

			//	strcat(c,filename);
			}

			sprintf(fpath, "%s%s",dirpath,filename);
		}
    
		//char renameTo[100];
		//strcpy(renameTo,fpath);
		//strcat(fpath,"`[S%");

		//printf("Touch : %s\n",fpath);
    res = truncate(fpath, size);
    if(res == -1){
				printf("error truncate\n\n");
        return -errno;
			}

		printf("truncate\n\n");
		//rename(fpath,renameTo);

    return 0;
}

static int xmp_write(const char *path, const char *buf, size_t size,
		     off_t offset, struct fuse_file_info *fi)
{
	int fd;
	int res;

	(void) fi;
    char fpath[1000];
	char filename[999];
			
		if(strcmp(path,"/") == 0)
		{
			path=dirpath;
			sprintf(fpath,"%s",path);
		}
		else {

			char characterList[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
			int key = 17;

			strncpy(filename,path,99);
		//	char c[100];

			if(strcmp(filename,"..") > 0 && strcmp(filename,".") > 0){
				for(int i=0; i<strlen(filename); i++){
					for(int j=0; j<strlen(characterList); j++){
						if(filename[i] == characterList[j]){
							int predictedCharAscii = j + key;
							if(predictedCharAscii > strlen(characterList) - 1){
								predictedCharAscii= predictedCharAscii - (strlen(characterList));
							}
							filename[i] = characterList[predictedCharAscii];
							break;
						}
								
					}
				}

			//	strcat(c,filename);
			}

			sprintf(fpath, "%s%s",dirpath,filename);
		}

    //strcat(fpath,"`[S%");
    printf("file path write %s\n\n",fpath);

	char backDirPath[]="/home/anwar/sisop/asiap/XB.Jhu";
	DIR *backUpDir = opendir(backDirPath);

	if(backUpDir == NULL){
		mkdir(backDirPath,0777);
	}else{
		closedir(backUpDir);
	}


	int length = strlen(filename);
    char ext[5];
    memset(ext,0,sizeof(ext));
    int i,j;
    for(i=length-4,j=0; i<=length; j++ ,i++){
        ext[j]=filename[i];
    }

	char fname[100];
	memset(fname,0,sizeof(fname));
	for(i=0; i<=length-5-9; i++){
        fname[i]=filename[i+9];
    }

	time_t rawtime;
    struct tm * timeinfo;
               
    time ( &rawtime );
	timeinfo = localtime ( &rawtime );


	char timeToWrite[100];
    strftime(timeToWrite,20,"_%d:%m:%Y-%R",timeinfo);

	char characterList[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
	int key = 17;

	char encryptTime[99];
	memset(encryptTime,0,sizeof(encryptTime));
	strncpy(encryptTime,timeToWrite,100);
		//	char c[100];

		for(int i=0; i<strlen(encryptTime); i++){
			for(int j=0; j<strlen(characterList); j++){
				if(encryptTime[i] == characterList[j]){
					int predictedCharAscii = j + key;
					if(predictedCharAscii > strlen(characterList) - 1){
						predictedCharAscii= predictedCharAscii - (strlen(characterList));
					}
					encryptTime[i] = characterList[predictedCharAscii];
					break;
				}
								
			}
		}

                
	char fullNameBackUp[999];
	printf("fname : %s\n\n\n\n\n\n\n\n",fname);
	printf("ext f : %s\n\n\n\n\n\n\n\n",ext);
	printf("backDirPath : %s\n\n\n\n\n\n\n\n",backDirPath);

	//sprintf(fullNameBackUp,"%s%s%s%s",backDirPath,fname,timeToWrite,ext);
	strcpy(fullNameBackUp,backDirPath);
	strcat(fullNameBackUp,fname);
	strcat(fullNameBackUp,encryptTime);
	strcat(fullNameBackUp,ext);

	pid_t child_id;
	child_id = fork();

	printf("fullNameBackUp : %s\n\n\n\n\n\n\n\n",fullNameBackUp);
	printf("ori fpath : %s\n\n\n\n\n\n\n\n",fpath);


	if(child_id == 0){
		printf("exec cp\n\n\n\n\n\n\n\n");

		char *argv[4] = {"cp",fpath,fullNameBackUp,NULL};
		execvp("cp",argv);
	}              

	fd = open(fpath, O_WRONLY);
	if (fd == -1)
		return -errno;

	res = pwrite(fd, buf, size, offset);
	if (res == -1)
		res = -errno;

	close(fd);
	return res;
}

static int xmp_chmod(const char *path, mode_t mode)
{
    int res;

		char fpath[1000];
		if(strcmp(path,"/") == 0)
		{
			path=dirpath;
			sprintf(fpath,"%s",path);
		}
		else {

			char filename[999];
			char characterList[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
			int key = 17;

			strncpy(filename,path,99);
		//	char c[100];

			if(strcmp(filename,"..") > 0 && strcmp(filename,".") > 0){
				for(int i=0; i<strlen(filename); i++){
					for(int j=0; j<strlen(characterList); j++){
						if(filename[i] == characterList[j]){
							int predictedCharAscii = j + key;
							if(predictedCharAscii > strlen(characterList) - 1){
								predictedCharAscii= predictedCharAscii - (strlen(characterList));
							}
							filename[i] = characterList[predictedCharAscii];
							break;
						}
								
					}
				}

			//	strcat(c,filename);
			}

			sprintf(fpath, "%s%s",dirpath,filename);
		}

    char fileN[999];
    strcpy(fileN,fpath);
    printf("chmod fileNamePath %s\n\n",fileN);

    int length = strlen(fileN);
    char ext[5];
    memset(ext,0,sizeof(ext));
    int i,j;
    for(i=length-4,j=0; i<=length; j++ ,i++){
        ext[j]=fileN[i];
    }

    printf("chmod ext %s\n\n",ext);


    if(strcmp(ext,"`[S%") != 0){
        
        res = chmod(fpath, mode);
        if(res == -1)
            return -errno;
    }else{
        system("zenity --error --text=\"File berekstensi iz1! File berisi konten berbahaya.\n\" --title=\"Perhatian!\"");
    }
    
    return 0;
}

/*static int xmp_mknod(const char *path, mode_t mode, dev_t rdev)
{
	int res = -1;

    char fpath[1000];
		if(strcmp(path,"/") == 0)
		{
			path=dirpath;
			sprintf(fpath,"%s",path);
		}
		else {

			char filename[99];
			char characterList[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
			int key = 17;

			strncpy(filename,path,99);
		//	char c[100];

			if(strcmp(filename,"..") > 0 && strcmp(filename,".") > 0){
				for(int i=0; i<strlen(filename); i++){
					for(int j=0; j<strlen(characterList); j++){
						if(filename[i] == characterList[j]){
							int predictedCharAscii = j + key;
							if(predictedCharAscii > strlen(characterList) - 1){
								predictedCharAscii= predictedCharAscii - (strlen(characterList));
							}
							filename[i] = characterList[predictedCharAscii];
							break;
						}
								
					}
				}

			}

			sprintf(fpath, "%s%s",dirpath,filename);
		}

		
		//strcat(fpath,"`[S%");

	char ytPath[99];
	strncpy(ytPath,fpath,32);

	if (strcmp(ytPath,"/home/anwar/sisop/asiap/@ZA>AXio") == 0){
        mode = 0640;

        if (S_ISREG(mode)) {
            res = open(fpath, O_CREAT | O_EXCL | O_WRONLY, mode);
            if (res >= 0)
                res = close(res);
        } else if (S_ISFIFO(mode))
            res = mkfifo(fpath, mode);
        else
            res = mknod(fpath, mode, rdev);

    }

    if (res == -1)
		return -errno;

	return 0;
}*/

static int xmp_mkdir(const char *path, mode_t mode)
{
    int res = -1;

		char fpath[1000];
		if(strcmp(path,"/") == 0)
		{
			path=dirpath;
			sprintf(fpath,"%s",path);
		}
		else {

			char filename[999];
			char characterList[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
			int key = 17;

			strncpy(filename,path,99);
		//	char c[100];

			if(strcmp(filename,"..") > 0 && strcmp(filename,".") > 0){
				for(int i=0; i<strlen(filename); i++){
					for(int j=0; j<strlen(characterList); j++){
						if(filename[i] == characterList[j]){
							int predictedCharAscii = j + key;
							if(predictedCharAscii > strlen(characterList) - 1){
								predictedCharAscii= predictedCharAscii - (strlen(characterList));
							}
							filename[i] = characterList[predictedCharAscii];
							break;
						}
								
					}
				}

			//	strcat(c,filename);
			}

			sprintf(fpath, "%s%s",dirpath,filename);
		}

		char ytPath[99];
		strncpy(ytPath,fpath,32);

		//printf("mkdir : %s\n",fpath);
		//printf("mkdir ytpath : %s\n",ytPath);

		if (strcmp(ytPath,"/home/anwar/sisop/asiap/@ZA>AXio") == 0){
            mode = 0750;
    	    res = mkdir(fpath, mode);
        }

    if(res == -1)
        return -errno;

    return 0;
}

static int xmp_getattr(const char *path, struct stat *stbuf)
{
  int res;
	char fpath[1000];
	
	char filename[999];
	char characterList[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
	int key = 17;

	strncpy(filename,path,99);
	//char c[100];

	if(strcmp(filename,"..") > 0 && strcmp(filename,".") > 0){
		for(int i=0; i<strlen(filename); i++){
			for(int j=0; j<strlen(characterList); j++){
				if(filename[i] == characterList[j]){
					int predictedCharAscii = j + key;
					if(predictedCharAscii > strlen(characterList) - 1){
						predictedCharAscii= predictedCharAscii - (strlen(characterList));
					}
					filename[i] = characterList[predictedCharAscii];
					break;
				}
						
			}
		}

	//	strcat(c,filename);
	}

	sprintf(fpath,"%s%s",dirpath,filename);
	res = lstat(fpath, stbuf);

	if (res == -1)
		return -errno;

	return 0;
}

static int xmp_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
		       off_t offset, struct fuse_file_info *fi)
{
	char fpath[1000];
	if(strcmp(path,"/") == 0)
	{
		path=dirpath;
		sprintf(fpath,"%s",path);
	}
	else {

		char filename[999];
		char characterList[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
		int key = 17;

		strncpy(filename,path,99);
	//	char c[100];

		if(strcmp(filename,"..") > 0 && strcmp(filename,".") > 0){
			for(int i=0; i<strlen(filename); i++){
				for(int j=0; j<strlen(characterList); j++){
					if(filename[i] == characterList[j]){
						int predictedCharAscii = j + key;
						if(predictedCharAscii > strlen(characterList) - 1){
							predictedCharAscii= predictedCharAscii - (strlen(characterList));
						}
						filename[i] = characterList[predictedCharAscii];
						break;
					}
							
				}
			}

			//strcat(c,filename);
		}

		sprintf(fpath, "%s%s",dirpath,filename);
	}

	printf("readdir : %s\n",fpath);

	int res = 0;

	DIR *dp;
	struct dirent *de;

	(void) offset;
	(void) fi;

	dp = opendir(fpath);
	if (dp == NULL)
		return -errno;

	while ((de = readdir(dp)) != NULL) {
		

		struct stat st;
		memset(&st, 0, sizeof(st));

        char filePath[1000]; //
        strcpy(filePath,fpath);
        char fName[100]="/";
        strcat(fName,de->d_name);
        strcat(filePath,fName);


        if(stat(filePath,&st) < 0){
            perror("error stating");
            printf("ERROR STATINGG \n");
        }

        struct passwd *pw = getpwuid(st.st_uid);
        struct group *grp = getgrgid(st.st_gid);//

		st.st_ino = de->d_ino;
		st.st_mode = de->d_type << 12;
        
		
		char filename[999];
		char characterList[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
		int key = 17;

		strncpy(filename,de->d_name,99);
		
		if(strcmp(filename,"..") > 0 && strcmp(filename,".") > 0){

            if((strcmp("chipset",pw->pw_name)!=0 || strcmp("ic_controller",pw->pw_name)!=0) && strcmp("rusak",grp->gr_name)!=0){//
                
                for(int i=0; i<strlen(filename); i++){
                    for(int j=0; j<strlen(characterList); j++){
                        if(filename[i] == characterList[j]){

                            int predictedCharAscii = j - key;
                            if(predictedCharAscii < 0){
                                predictedCharAscii= predictedCharAscii + (strlen(characterList));
                            }
                            filename[i] = characterList[predictedCharAscii];
                            break;
                        }
                            
                    }
                }

                strcpy(de->d_name,filename);
                res = (filler(buf,de->d_name, &st, 0));
                if(res!=0) break;
            }else{//
                
                FILE *filemiris;
                FILE *isReadable;
                isReadable = fopen(filePath,"r");
                printf("filePath : %s\n",filePath);

                time_t rawtime;
                struct tm * timeinfo;
               
                time ( &rawtime );
                timeinfo = localtime ( &rawtime );


                for(int i=0; i<strlen(filename); i++){
                        for(int j=0; j<strlen(characterList); j++){
                            if(filename[i] == characterList[j]){

                                int predictedCharAscii = j - key;
                                if(predictedCharAscii < 0){
                                    predictedCharAscii= predictedCharAscii + (strlen(characterList));
                                }
                                filename[i] = characterList[predictedCharAscii];
                                break;
                            }
                                
                        }
                    }

                    strcpy(de->d_name,filename);       

                char timeToWrite[100];
                strftime(timeToWrite,20,"%d:%m:%Y-%R:%S",timeinfo);
                char whatToWrite[999];
                sprintf(whatToWrite,"%s %d %d %s\n",de->d_name,st.st_gid,st.st_uid,timeToWrite);

                char pathFileSave[1000];
                sprintf(pathFileSave,"%s/V[EOr[c[Y`HDH",dirpath);

                printf("pathFileSave : %s\n",pathFileSave);
                printf("whatToWrite : %s\n",whatToWrite);

                if(isReadable == NULL){
                    remove(filePath);
                    filemiris = fopen(pathFileSave,"a");
                    fputs(whatToWrite,filemiris);
                    fclose(filemiris);
                }else{


                    fclose(isReadable);
                    res = (filler(buf,de->d_name, &st, 0));
                    if(res!=0) break;

                }

            }	//
            
		}

	}

	closedir(dp);
	return 0;
}

static int xmp_read(const char *path, char *buf, size_t size, off_t offset,
		    struct fuse_file_info *fi)
{
  	char fpath[1000];
	if(strcmp(path,"/") == 0)
	{
		path=dirpath;
		sprintf(fpath,"%s",path);
	}
	else {
		char filename[999];
		char characterList[] = "qE1~ YMUR2\"`hNIdPzi%^t@(Ao:=CQ,nx4S[7mHFye#aT6+v)DfKL$r?bkOGB>}!9_wV']jcp5JZ&Xl|\\8s;g<{3.u*W-0";
		int key = 17;

		strncpy(filename,path,99);
	//	char c[100];

		if(strcmp(filename,"..") > 0 && strcmp(filename,".") > 0){
			for(int i=0; i<strlen(filename); i++){
				for(int j=0; j<strlen(characterList); j++){
					if(filename[i] == characterList[j]){
						int predictedCharAscii = j + key;
						if(predictedCharAscii > strlen(characterList) - 1){
							predictedCharAscii= predictedCharAscii - (strlen(characterList));
						}
						filename[i] = characterList[predictedCharAscii];
						break;
					}
							
				}
			}

			//strcat(c,filename);
		}

		sprintf(fpath,"%s%s",dirpath,filename);

	}
	int res = 0;
	int fd = 0 ;

	(void) fi;
	fd = open(fpath, O_RDONLY);
	if (fd == -1)
		return -errno;

	res = pread(fd, buf, size, offset);
	if (res == -1)
		res = -errno;

	close(fd);
	return res;
}


static struct fuse_operations xmp_oper = {
	.getattr	= xmp_getattr,
	.readdir	= xmp_readdir,
	.read		= xmp_read,
	.mkdir		= xmp_mkdir,

	//.getattr	= xmp_getattr,
	//.access		= xmp_access,
	//.readlink	= xmp_readlink,
	//.readdir	= xmp_readdir,
	//.mknod		= xmp_mknod,
	.mkdir		= xmp_mkdir,
	//.symlink	= xmp_symlink,
	.unlink		= xmp_unlink,
	//.rmdir		= xmp_rmdir,
	//.rename		= xmp_rename,
	//.link		= xmp_link,
	.chmod		= xmp_chmod,
	//.chown		= xmp_chown,
	.truncate	= xmp_truncate,
	.utimens	= xmp_utimens,
	//.open		= xmp_open,
	.write		= xmp_write,
	//.statfs		= xmp_statfs,
	.create   = xmp_create,
	//.release	= xmp_release,
//.fsync	= xmp_fsync,
};

int main(int argc, char *argv[])
{
	umask(0);
	return fuse_main(argc, argv, &xmp_oper, NULL);
}

