#include <main/Texture2D.hpp>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Texture2D::Texture2D(const char *pathToTexture) {
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    this->pathToTexture = pathToTexture;
}

void Texture2D::bind() {
    glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture2D::bind(unsigned int activeTexture) {
    glActiveTexture(activeTexture);
    glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture2D::deleteTexture() {
    glDeleteTextures(1, &ID);
}

void Texture2D::setParameter(unsigned int parameterName, unsigned int parameterValue) {
    glTexParameteri(GL_TEXTURE_2D, parameterName, parameterValue);
}

int Texture2D::loadTexture(unsigned int formatStorageOpenGL, unsigned int formatImage, unsigned int dataTypeImage) {
    int width, height, nrChannels;
    unsigned char *data = stbi_load(pathToTexture, &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, formatStorageOpenGL, width, height, 0, formatImage, dataTypeImage, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(data);
    } else {
        std::cout << "Failed to load texture: " << pathToTexture << std::endl;
        stbi_image_free(data);
        return -1;
    }

    return 0;
}