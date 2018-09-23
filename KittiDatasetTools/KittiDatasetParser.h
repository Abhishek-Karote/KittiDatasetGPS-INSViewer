#ifndef KITTIDATASETPARSER_H
#define KITTIDATASETPARSER_H

#include <QObject>
#include "Core.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include "EKF.h"

namespace kitti_dataset_tools {
enum KittiDataFormat {
  lat,
  lon,
  alt,
  roll,
  pitch,
  yaw,
  vn,
  ve,
  vf,
  vl,
  vu,
  ax,
  ay,
  az,
  af,
  al,
  au,
  wx,
  wy,
  wz,
  wf,
  wl,
  wu,
  pos_accuracy,
  vel_accuracy,
  navstat,
  numsats,
  posmode,
  velmode,
  orimode
};
class KittiDatasetParser : public QObject
{
    Q_OBJECT
public:
  explicit KittiDatasetParser(QObject *parent = nullptr);
  void setParserSettings(std::string path_to_oxts_folder, EKF_INS::EKF &ekf);
  bool loadDataset();
  void initState();
  void startPlayingData();

private:
  bool loadTimestamp();
  bool loadData();

  EKF_INS::EKF *ekf_;
  std::string path_to_oxts_folder_;
  bool is_playing_;
  bool is_data_ready_;
  std::vector<uint64_t> timestamp_vec_;
  Eigen::MatrixXd *gps_vec_;
  Eigen::MatrixXd *accelerometer_vec_, *gyro_vec_;

signals:
  void newDataIsReady();
};
} // namespace kitti_dataset_tools
#endif // KITTIDATASETPARSER_H
