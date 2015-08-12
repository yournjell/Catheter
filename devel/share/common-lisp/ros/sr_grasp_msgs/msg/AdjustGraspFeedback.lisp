; Auto-generated. Do not edit!


(cl:in-package sr_grasp_msgs-msg)


;//! \htmlinclude AdjustGraspFeedback.msg.html

(cl:defclass <AdjustGraspFeedback> (roslisp-msg-protocol:ros-message)
  ((state
    :reader state
    :initarg :state
    :type cl:fixnum
    :initform 0)
   (quality
    :reader quality
    :initarg :quality
    :type sr_grasp_msgs-msg:KCL_GraspQuality
    :initform (cl:make-instance 'sr_grasp_msgs-msg:KCL_GraspQuality)))
)

(cl:defclass AdjustGraspFeedback (<AdjustGraspFeedback>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AdjustGraspFeedback>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AdjustGraspFeedback)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sr_grasp_msgs-msg:<AdjustGraspFeedback> is deprecated: use sr_grasp_msgs-msg:AdjustGraspFeedback instead.")))

(cl:ensure-generic-function 'state-val :lambda-list '(m))
(cl:defmethod state-val ((m <AdjustGraspFeedback>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:state-val is deprecated.  Use sr_grasp_msgs-msg:state instead.")
  (state m))

(cl:ensure-generic-function 'quality-val :lambda-list '(m))
(cl:defmethod quality-val ((m <AdjustGraspFeedback>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:quality-val is deprecated.  Use sr_grasp_msgs-msg:quality instead.")
  (quality m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<AdjustGraspFeedback>)))
    "Constants for message type '<AdjustGraspFeedback>"
  '((:SELECTING . 0)
    (:GAITING . 1)
    (:EXPLORING . 2)
    (:IMPROVING . 3))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'AdjustGraspFeedback)))
    "Constants for message type 'AdjustGraspFeedback"
  '((:SELECTING . 0)
    (:GAITING . 1)
    (:EXPLORING . 2)
    (:IMPROVING . 3))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AdjustGraspFeedback>) ostream)
  "Serializes a message object of type '<AdjustGraspFeedback>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'state)) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'quality) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AdjustGraspFeedback>) istream)
  "Deserializes a message object of type '<AdjustGraspFeedback>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'state)) (cl:read-byte istream))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'quality) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AdjustGraspFeedback>)))
  "Returns string type for a message object of type '<AdjustGraspFeedback>"
  "sr_grasp_msgs/AdjustGraspFeedback")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AdjustGraspFeedback)))
  "Returns string type for a message object of type 'AdjustGraspFeedback"
  "sr_grasp_msgs/AdjustGraspFeedback")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AdjustGraspFeedback>)))
  "Returns md5sum for a message object of type '<AdjustGraspFeedback>"
  "f53e9a8ba34d5929c78e8792c960b05d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AdjustGraspFeedback)))
  "Returns md5sum for a message object of type 'AdjustGraspFeedback"
  "f53e9a8ba34d5929c78e8792c960b05d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AdjustGraspFeedback>)))
  "Returns full string definition for message of type '<AdjustGraspFeedback>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# Feedback~%# State shows what the node is currently doing.~%uint8 SELECTING=0~%uint8 GAITING=1~%uint8 EXPLORING=2~%uint8 IMPROVING=3~%uint8 state~%# A percentage or other measure of the quality of the grasp.~%KCL_GraspQuality quality~%~%~%================================================================================~%MSG: sr_grasp_msgs/KCL_GraspQuality~%# All 3D vectors are referenced in the fingertip core center~%~%Header header					# stamp~%geometry_msgs/Vector3 resultant_force  		# Resultant Force~%geometry_msgs/Vector3 resultant_torque      	# Resultant Torque~%float64[] hull_force_dist			# distances from force hull surface to origin in each octant~%float64[] hull_torque_dist			# distances from force hull surface to origin in each octant~%float64 hull_volume_force			# volume of force hull. basically the grasp quality. unitless.~%float64 hull_volume_torque			# volume of torque hull~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AdjustGraspFeedback)))
  "Returns full string definition for message of type 'AdjustGraspFeedback"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# Feedback~%# State shows what the node is currently doing.~%uint8 SELECTING=0~%uint8 GAITING=1~%uint8 EXPLORING=2~%uint8 IMPROVING=3~%uint8 state~%# A percentage or other measure of the quality of the grasp.~%KCL_GraspQuality quality~%~%~%================================================================================~%MSG: sr_grasp_msgs/KCL_GraspQuality~%# All 3D vectors are referenced in the fingertip core center~%~%Header header					# stamp~%geometry_msgs/Vector3 resultant_force  		# Resultant Force~%geometry_msgs/Vector3 resultant_torque      	# Resultant Torque~%float64[] hull_force_dist			# distances from force hull surface to origin in each octant~%float64[] hull_torque_dist			# distances from force hull surface to origin in each octant~%float64 hull_volume_force			# volume of force hull. basically the grasp quality. unitless.~%float64 hull_volume_torque			# volume of torque hull~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AdjustGraspFeedback>))
  (cl:+ 0
     1
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'quality))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AdjustGraspFeedback>))
  "Converts a ROS message object to a list"
  (cl:list 'AdjustGraspFeedback
    (cl:cons ':state (state msg))
    (cl:cons ':quality (quality msg))
))
