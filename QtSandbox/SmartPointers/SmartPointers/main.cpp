#include <iostream>
#include <memory>
#include <string>

class Entity
{
protected:
    std::string Name;
public:
    Entity(std::string name)
    {
        Name = name;
        std::cout << "Created Enity: " << Name << std::endl;

    }

    ~Entity()
    {
        std::cout << "Destroyed Entity: " << Name << std::endl;
    }
};


int main()
{
    {
        std::cout << "start scope0" << std::endl;
        std::shared_ptr<Entity> sharedEntity0;
        std::weak_ptr<Entity> weakEntity0;
        {
            std::cout << "start scope 1" << std::endl;

            std::unique_ptr<Entity> entity(new Entity("unique")); //unique pointer cannot be copied
            //std::unique_ptr<Entity> saferEntity = std::make_unique<Entity>(); //safer but apparenlty not available here

            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>("shared");
            std::shared_ptr<Entity> weakEntity = std::make_shared<Entity>("weak");
            sharedEntity0 = sharedEntity;
            weakEntity0 = weakEntity; //this one should be destroyed within this scope
            std::cout << "End Scope 1" << std::endl;
        }


        //entity is deleted from memory at end of this scope

        std::cout << "End Scope 0" << std::endl;
    }




    return 0;
}
