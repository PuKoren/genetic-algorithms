#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

class IGameObject{
public:
    virtual ~IGameObject() {};
    virtual void Draw() = 0;
    virtual void Init() = 0;
    virtual void Update(double elapsedTime) = 0;
};

#endif
