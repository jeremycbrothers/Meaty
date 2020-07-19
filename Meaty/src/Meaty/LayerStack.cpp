#include "mtpch.h"
#include "LayerStack.h"

namespace Meaty
{
	Meaty::LayerStack::LayerStack()
	{
		layerInsert = layers.begin();
	}

	Meaty::LayerStack::~LayerStack()
	{
		for (Layer* layer : layers)
		{
			delete layer;
		}
	}

	void Meaty::LayerStack::PushLayer(Layer* layer)
	{
		layerInsert = layers.emplace(layerInsert, layer);
	}

	void Meaty::LayerStack::PushOverlay(Layer* overlay)
	{
		layers.emplace_back(overlay);
	}

	void Meaty::LayerStack::PopLayer(Layer* layer)
	{
		auto iterator = std::find(layers.begin(), layers.end(), layer);
		if (iterator != layers.end())
		{
			layers.erase(iterator);
			layerInsert--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto iterator = std::find(layers.begin(), layers.end(), overlay);
		if (iterator != layers.end())
		{
			layers.erase(iterator);
		}
	}
}
