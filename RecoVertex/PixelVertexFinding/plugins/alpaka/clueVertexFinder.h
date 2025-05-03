#include <alpaka/alpaka.hpp>
#include <algorithm>
#include <chrono>
#include <vector>
#include <numeric>

#include <iostream>

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "HeterogeneousCore/AlpakaCore/interface/alpaka/global/EDProducer.h"
#include "HeterogeneousCore/AlpakaCore/interface/alpaka/Event.h"
#include "HeterogeneousCore/AlpakaCore/interface/alpaka/EventSetup.h"
#include "HeterogeneousCore/AlpakaCore/interface/alpaka/EDPutToken.h"
#include "HeterogeneousCore/AlpakaCore/interface/alpaka/ESGetToken.h"
#include "HeterogeneousCore/AlpakaCore/interface/alpaka/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescription.h"

#include "FWCore/ParameterSet/interface/ConfigurationDescriptions.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/Math/interface/Error.h"

#include "DataFormats/TrackSoA/interface/alpaka/TracksSoACollection.h"
#include "DataFormats/TrackSoA/interface/TracksDevice.h"
#include "DataFormats/VertexSoA/interface/alpaka/ZVertexSoACollection.h"
#include "DataFormats/VertexSoA/interface/ZVertexDevice.h"

namespace ALPAKA_ACCELERATOR_NAMESPACE {

   template <typename TrackerTraits>
   class Producer {

   public:
     Producer(float dc,
              float rhoc,
              float dm,
              int PBin,
              bool wtAvg,
              )
         : m_dc(dc),
           m_rhoc(rhoc),
           m_dm(dm),
           m_PBin(PBin),
           m_wtAvg(wtAvg) {}
     
     ~Producer() = default;

     // need to figure out what the return type is
     auto makeClusters (PointsHost& h_points, PointsDevice& d_points, Queue& queue);

   private: 
     float m_dc;
     float m_rhoc;
     float m_dm;
     int m_PBin;
     bool wtAvg;
 };

} // namespace ALPAKA_ACCELERATOR_NAMESPACE

