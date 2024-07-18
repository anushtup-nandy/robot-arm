#ifndef MODEL_H
#define MODEL_H

#include "mesh.h"
#include "shader_s.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <string>

class Model{
    public:
        Model(char *path);
        void Draw(Shader &shader); //loop over each mesh and call that meshes draw function
    private:
        std::vector<Mesh> meshes;
        std::string directory;
        void loadModel(std::string path);
        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
};
#endif