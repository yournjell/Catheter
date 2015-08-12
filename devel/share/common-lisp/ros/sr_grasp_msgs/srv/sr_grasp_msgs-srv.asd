
(cl:in-package :asdf)

(defsystem "sr_grasp_msgs-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :sensor_msgs-msg
               :shape_msgs-msg
               :sr_grasp_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "PclTransform" :depends-on ("_package_PclTransform"))
    (:file "_package_PclTransform" :depends-on ("_package"))
    (:file "KCL_Sensor_Bias" :depends-on ("_package_KCL_Sensor_Bias"))
    (:file "_package_KCL_Sensor_Bias" :depends-on ("_package"))
    (:file "PclFilter" :depends-on ("_package_PclFilter"))
    (:file "_package_PclFilter" :depends-on ("_package"))
    (:file "KCL_PoseCorrection" :depends-on ("_package_KCL_PoseCorrection"))
    (:file "_package_KCL_PoseCorrection" :depends-on ("_package"))
    (:file "KCL_GraspQualityQuery" :depends-on ("_package_KCL_GraspQualityQuery"))
    (:file "_package_KCL_GraspQualityQuery" :depends-on ("_package"))
  ))