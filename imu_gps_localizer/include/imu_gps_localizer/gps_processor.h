#pragma once 

#include <Eigen/Dense>

#include "imu_gps_localizer/base_type.h"

namespace ImuGpsLocalization {

class GpsProcessor {
public:
    GpsProcessor();

    bool UpdateStateByGpsPosition(const Eigen::Vector3d& init_lla, const GpsPositionDataPtr gps_data_ptr, State* state);

    bool UpdateStateByGpsVelocity(const Eigen::Vector3d& init_lla, const GpsVelocityDataPtr gps_data_ptr, State* state);
    
private:    
    void ComputeJacobianAndResidual(const Eigen::Vector3d& init_lla,  
                                    const GpsPositionDataPtr gps_data, 
                                    const State& state,
                                    Eigen::Matrix<double, 3, 18>* jacobian,
                                    Eigen::Vector3d* residual);
    
    void ComputeJacobianAndResidual(const Eigen::Vector3d& init_lla,  
                                    const GpsVelocityDataPtr gps_data, 
                                    const State& state,
                                    Eigen::Matrix<double, 3, 18>* jacobian,
                                    Eigen::Vector3d* residual);
};

void AddDeltaToState(const Eigen::Matrix<double, 18, 1>& delta_x, State* state);

}  // namespace ImuGpsLocalization