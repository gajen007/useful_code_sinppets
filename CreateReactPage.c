#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void main(int argc, char const *argv[]){
	if (argc>2||argc<2)
	{
		printf("Usage: ./exefileName ReactPageName\nOutput: ReactPageName.js\n");
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
		fprintf(fp,"%s",argv[1]);
		fprintf(fp,"%s","() {\n\tconst [dataContainer, fillData] = useState(\"\")\n\tconst router = useRouter()\n\tconst dispatchWhenClicked = useDispatch()\n\tconst fetchFunction = async () => {\n\t\ttry {\n\t\t	await axios.get(URL).then(res => { fillData(res.data) })\n\t\t}\n\t\tcatch (e) {\n\t\t	alert(\"Fetch Error\"); console.log(e)\n\t\t}\n\t}\n\n\t\tuseEffect(() => { fetchFunction() }, [])\n\n\tconst linkClicked=(dataID)=>{\n\t\trouter.push(\"path_to_single_data/\"+dataID)\n\t}\n\n\treturn <ol>\n\t\t{\n\t\t\tdataContainer.map((data) => {\n\t\t\t\treturn (<li><Link onClick={linkClicked(data.id)} >{data.objFieldName}</Link></li>)\n\t\t\t})\n\t\t}\n\t</ol>\n}");
		fclose(fp);
		printf("%s is ready.!\n",fileNameWithExtension);
	}
}
