#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void main(int argc, char const *argv[]){
	if (argc>2||argc<2)
	{
		printf("Usage: ./exefileName ReactComponentName\nOutput: ReactComponentName.js\n");
	}
	else{
		
		char *fileNameOnly;
		fileNameOnly=(char*)malloc(sizeof(2048));
		strcpy(fileNameOnly, argv[1]);

		char *fileNameWithExtension;
		fileNameWithExtension=(char*)malloc(sizeof(2048));
		strcpy(fileNameWithExtension, argv[1]);
		strcat(fileNameWithExtension,".js");
		FILE *fp=fopen(fileNameWithExtension,"w");

		fprintf(fp,"%s","import React, { useEffect, useState } from \"react\"\nimport { useRouter } from \"next/router\"\nimport Link from \"next/link\"\nimport axios from \"axios\"\nimport { useDispatch } from \"react-redux\"\n\nexport default function ");
		fprintf(fp,"%s",fileNameOnly);
		fprintf(fp,"%s","() {\n\treturn <div>Hello World</div>\n}");
		fclose(fp);
		printf("%s is ready.!\n",fileNameWithExtension);
	}
}