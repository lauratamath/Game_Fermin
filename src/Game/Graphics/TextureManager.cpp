#include "TextureManager.h"
#include <print.h>

std::map<std::string, Texture*> TextureManager::textures;

Texture* TextureManager::LoadTexture(const std::string& filename, SDL_Renderer* renderer, PixelShader shader) {
  print("LOADED");
  if (textures.count(filename + shader.name) > 0) {
    print("IN IF");
    return textures[filename + shader.name];
  }

  print("NOT IF");
  Texture* texture = new Texture(renderer);
  print("TEXTURE");
  texture->load("assets/" + filename, shader);
  print("LOADEDDDD");

  textures[filename + shader.name] = texture;
  print("ASSIGNMENT");
  return texture;
}

void TextureManager::UnloadTexture(const std::string& filename, const std::string& shadername) {
  if (textures.count(filename + shadername) > 0) {
    delete textures[filename + shadername];
    textures.erase(filename + shadername);
  }
}

Texture* TextureManager::GetTexture(const std::string& filename, const std::string& shadername) {
  if (textures.count(filename + shadername) > 0) {
    return textures[filename + shadername];
  }
  return nullptr;
}