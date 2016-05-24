#include <stdlib.h>
#include <stdio.h>

#include <GL/glut.h>

/* assimp include files. These three are usually needed. */
#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

/* the global Assimp scene object */
const struct aiScene* scene = NULL;

void main()
{
	struct aiLogStream stream;


	/* get a handle to the predefined STDOUT log stream and attach
	it to the logging system. It remains active for all further
	calls to aiImportFile(Ex) and aiApplyPostProcessing. */
	stream = aiGetPredefinedLogStream(aiDefaultLogStream_STDOUT, NULL);
	aiAttachLogStream(&stream);

	/* ... same procedure, but this stream now writes the
	log messages to assimp_log.txt */
	stream = aiGetPredefinedLogStream(aiDefaultLogStream_FILE, "assimp_log.txt");
	aiAttachLogStream(&stream);

	scene = aiImportFile("CTDummy(LE).stl", aiProcessPreset_TargetRealtime_MaxQuality);

	system("pause");
}