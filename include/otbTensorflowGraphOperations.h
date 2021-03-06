/*=========================================================================

  Copyright (c) Remi Cresson (IRSTEA). All rights reserved.


     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef MODULES_REMOTE_OTBTENSOFLOW_INCLUDE_OTBTENSORFLOWGRAPHOPERATIONS_H_
#define MODULES_REMOTE_OTBTENSOFLOW_INCLUDE_OTBTENSORFLOWGRAPHOPERATIONS_H_

// Tensorflow graph protobuf
#include "tensorflow/core/public/session.h"
#include "tensorflow/core/platform/env.h"
#include <tensorflow/core/protobuf/meta_graph.pb.h>

// Tensorflow SavedModel
#include "tensorflow/cc/saved_model/loader.h"
#include "tensorflow/cc/saved_model/tag_constants.h"

// ITK exception
#include "itkMacro.h"

namespace otb {
namespace tf {

// Restore a model from a path
void RestoreModel(const std::string path, tensorflow::SavedModelBundle & bundle);

// Restore a model from a path
void SaveModel(const std::string path, tensorflow::SavedModelBundle & bundle);

// Load a session and a graph from a folder
void LoadModel(const std::string path, tensorflow::SavedModelBundle & bundle);

// Load a graph from a .meta file
tensorflow::GraphDef LoadGraph(std::string filename);

// Get the following attributes of the specified tensors (by name) of a graph:
// - shape
// - datatype
// Here we assume that the node's output is a tensor
void GetTensorAttributes(const tensorflow::GraphDef & graph, std::vector<std::string> & tensorsNames,
    std::vector<tensorflow::TensorShapeProto> & shapes, std::vector<tensorflow::DataType> & dataTypes);

// Print a lot of stuff about the specified nodes of the graph
void PrintNodeAttributes(const tensorflow::GraphDef & graph, std::vector<std::string> & nodesNames);

} // end namespace tf
} // end namespace otb

#include "otbTensorflowGraphOperations.cxx"

#endif /* MODULES_REMOTE_OTBTENSOFLOW_INCLUDE_OTBTENSORFLOWGRAPHOPERATIONS_H_ */
