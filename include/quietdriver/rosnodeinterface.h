//
// File rosnodeinterface.h
//
// Code generated for Simulink model 'quietdriver'.
//
// Model version                  : 5.36
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Tue Nov 19 01:06:48 2024
//

#ifndef _ROS_MATLAB_NODEINTERFACE_
#define _ROS_MATLAB_NODEINTERFACE_
#ifdef _MSC_VER

#pragma warning(push)
#pragma warning(disable : 4265)
#pragma warning(disable : 4458)
#pragma warning(disable : 4100)

#else

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"

#endif                                 //_MSC_VER

#include "quietdriver.h"
#include "quietdriver_types.h"
#include "rtwtypes.h"
#include <thread>
#include <atomic>
#include <chrono>
#include <utility>
#include <mutex>
#include <condition_variable>
#include <ros/ros.h>

namespace ros
{
  namespace matlab
  {
    //Semaphore using std::CV and std::mutex
    class Semaphore {
     public:
      std::mutex mMutex;
      std::condition_variable mCV;
      std::atomic_uint mCount;

      //
      Semaphore(int count = 0)
        : mCount(count)
      {
      }

      //
      inline void notify()
      {
        std::unique_lock<std::mutex> lock(mMutex);
        mCount++;
        mCV.notify_all();
      }

      //
      inline void wait()
      {
        std::unique_lock<std::mutex> lock(mMutex);
        while (mCount == 0) {
          mCV.wait(lock);
        }

        if (mCount)
          mCount--;
      }
    };

    //NodeInterface
    class NodeInterface {
      NodeInterface(const NodeInterface& );
      NodeInterface& operator= (const NodeInterface& );

      //
      std::shared_ptr<ros::NodeHandle> mNode;
      std::shared_ptr<quietdriver> mModel;
      Semaphore mBaseRateSem;
      std::shared_ptr<std::thread> mBaseRateThread;
      std::shared_ptr<ros::WallTimer> mSchedulerTimer;

      //
      //
      Semaphore mStopSem;
      volatile boolean_T mRunModel;
     public:
      NodeInterface();
      ~NodeInterface();

      //
      void initialize(int argc, char ** argv);
      int run();
      void stop(void);
      void terminate(void);

      //
      boolean_T getStopRequestedFlag(void);
      void schedulerCallback(const ros::WallTimerEvent& ev);
      void baseRateTask(void);
      std::shared_ptr<ros::NodeHandle> getNode()
      {
        return mNode;
      }

      //
      std::shared_ptr<quietdriver> getModel()
      {
        return mModel;
      }
    };                                 //class NodeInterface

    std::shared_ptr<ros::matlab::NodeInterface> getNodeInterface();
  }                                    //namespace matlab
}                                      //namespace ros

#ifdef _MSC_VER

#pragma warning(pop)

#else

#pragma GCC diagnostic pop

#endif                                 //_MSC_VER
#endif                                 //_ROS_MATLAB_ROS2CGEN_MULTIRATE_
