#include <print.h>

#include "Pong.h"
#include "Systems.h"

#include "ECS/Entity.h"

#include "Game/Graphics/PixelShader.h"

Pong::Pong(const char* name, int width, int height)
  : Game(name, width, height)
{
  print("ONE");
  Scene* gameplayScene = createGameplayScene();
  print("TWO");
  setScene(gameplayScene);
  print("THREE");
}

Pong::~Pong() {
  
}

Scene* Pong::createGameplayScene() {
  Scene* scene = new Scene("GAMEPLAY SCENE");

  Entity white = scene->createEntity("Fermin1", 0, 0);
  auto& s = white.addComponent<SpriteComponent>(
    "Sprites/Cat/SpriteSheet.png",
    0, 0,
    48,
    8,
    1000
  );
  s.lastUpdate = SDL_GetTicks();

  Entity black = scene->createEntity("Fermin2", 50, 0);
  black.addComponent<SpriteComponent>(
    "Sprites/Cat/SpriteSheet.png", 
    0, 0,
    48,
    8,
    1000,
    PixelShader{
      [](Uint32 color) -> Uint32 { return (color == 0xcacbd0FF) ? 0xe0bd2cFF : color ; },
      "yellow"
    },
    SDL_GetTicks()
  );
  
  scene->addSetupSystem(new WorldSetupSystem());
  scene->addSetupSystem(new CameraSetupSystem());
  scene->addSetupSystem(new PlayerSetupSystem());

  scene->addSetupSystem(new TilemapSetupSystem(renderer));
  scene->addSetupSystem(new AutoTilingSetupSystem());
  scene->addRenderSystem(new TilemapRenderSystem());

  scene->addSetupSystem(new SpriteSetupSystem(renderer));
  scene->addRenderSystem(new SpriteRenderSystem());
  scene->addUpdateSystem(new SpriteUpdateSystem());
  /*


  */
  scene->addEventSystem(new PlayerInputSystem());
  scene->addUpdateSystem(new TileCollisionUpdateSystem());
  scene->addUpdateSystem(new MovementUpdateSystem());
  scene->addUpdateSystem(new PlayerSpriteUpdateSystem());
  scene->addUpdateSystem(new CameraFollowUpdateSystem());

  scene->addRenderSystem(new ColliderRenderSystem());
  scene->addRenderSystem(new TileColliderRenderSystem());

  return scene;
}
