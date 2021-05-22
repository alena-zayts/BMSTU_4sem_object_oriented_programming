#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "command_base.hpp"
#include "controller.hpp"
#include "factory_abstract.hpp"
#include "drawer_base.hpp"
#include "model_source_loader_base.hpp"
#include "camera_source_loader_base.hpp"

class AddCameraCommand : public BaseCommand
{
public:
    explicit AddCameraCommand(std::string model_name, std::string file_name, std::shared_ptr<BaseCameraSourceLoader> loader);
    void Run(std::shared_ptr<Controller> controller) override;

private:
    std::shared_ptr<BaseCameraSourceLoader> source_loader;
    std::string camera_name;
    std::string file_name;
};

class AddModelCommand : public BaseCommand
{
public:
    explicit AddModelCommand(std::string model_name, std::string file_name, std::shared_ptr<BaseModelSourceLoader> loader);

    void Run(std::shared_ptr<Controller> controller) override;

private:
    std::shared_ptr<BaseModelSourceLoader> source_loader;
    std::string model_name;
    std::string file_name;
};


class RemoveObjectCommand : public BaseCommand
{
public:
    RemoveObjectCommand(std::string object_name);
    void Run(std::shared_ptr<Controller> controller) override;

private:
    std::string object_name_;
};

class TransformObjectCommand : public BaseCommand
{
public:
    TransformObjectCommand(std::string object_name, Point<double> &move, Point<double> &scale, Point<double> &rotate);
    void Run(std::shared_ptr<Controller> controller) override;

private:
    std::string object_name_;
    Point<double> move_;
    Point<double> scale_;
    Point<double> rotate_;
};

class DrawCommand : public BaseCommand
{
public:
    explicit DrawCommand(std::shared_ptr<BaseDrawer> drawer);
    void Run(std::shared_ptr<Controller> controller) override;

private:
    std::shared_ptr<BaseDrawer> drawer_;
    std::shared_ptr<AbstractFactory> factory_;
};

class SetCameraCommand : public BaseCommand
{
public:
    explicit SetCameraCommand(std::string name);
    void Run(std::shared_ptr<Controller> Controller) override;

private:
    std::string name_;
};


#endif // COMMANDS_HPP
