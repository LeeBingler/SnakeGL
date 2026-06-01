#pragma once

#include <glad/glad.h>

class Texture2D {
    public:
        unsigned int ID;
        const char *pathToTexture;

        Texture2D(const char *pathToTexture);
        void bind();
        void bind(unsigned int activeTexture);
        void deleteTexture();
        void setParameter(unsigned int parameterName, unsigned int parameterValue);
        int loadTexture(unsigned int formatStorageOpenGL, unsigned int formatImage, unsigned int dataTypeImage);
};