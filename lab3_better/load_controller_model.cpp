#include "load_controller_model.hpp"
#include "director_model.hpp"
#include <memory.h>

ModelLoadController::ModelLoadController(std::shared_ptr<BaseModelBuilder> bld)
{
    builder_ = bld;
}

void ModelLoadController::SetSourceLoader(std::shared_ptr<BaseSourceLoader> loader)
{
    source_loader_ = loader;
}

std::shared_ptr<SceneObject> ModelLoadController::load(std::string model_name, std::string source_name)
{
    source_loader_->open(source_name);
    builder_->reset(model_name);

    Vector<Point<double>> points = this->source_loader_->ReadPoints();
    Vector<Link> links = this->source_loader_->ReadLinks();
    source_loader_->close();

    ModelDirector director;
    director.SetBuilder(builder_);

    return director.Build(points, links);
}

