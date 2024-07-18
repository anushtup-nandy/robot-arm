#ifndef MODEL_H
#define MODEL_H

#include "mesh.h"
#include "shader_s.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <string>

unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma = false);

class Model{
    public:
        std::vector<Mesh> meshes;
        std::string directory;
        std::vector<Texture> textures_loaded;
        bool gammaCorrection;
        Model(char *path);
        void Draw(Shader &shader); //loop over each mesh and call that meshes draw function
    private:
        
        void loadModel(std::string path);
        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
};
#endif