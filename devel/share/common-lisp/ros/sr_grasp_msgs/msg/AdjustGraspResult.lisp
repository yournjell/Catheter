; Auto-generated. Do not edit!


(cl:in-package sr_grasp_msgs-msg)


;//! \htmlinclude AdjustGraspResult.msg.html

(cl:defclass <AdjustGraspResult> (roslisp-msg-protocol:ros-message)
  ((quality
    :reader quality
    :initarg :quality
    :type sr_grasp_msgs-msg:KCL_GraspQuality
    :initform (cl:make-instance 'sr_grasp_msgs-msg:KCL_GraspQuality))
   (improved
    :reader improved
    :initarg :improved
    :type cl:boolean
    :initform cl:nil)
   (object
    :reader object
    :initarg :object
    :type cl:fixnum
    :initform 0))
)

(cl:defclass AdjustGraspResult (<AdjustGraspResult>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AdjustGraspResult>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AdjustGraspResult)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sr_grasp_msgs-msg:<AdjustGraspResult> is deprecated: use sr_grasp_msgs-msg:AdjustGraspResult instead.")))

(cl:ensure-generic-function 'quality-val :lambda-list '(m))
(cl:defmethod quality-val ((m <AdjustGraspResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:quality-val is deprecated.  Use sr_grasp_msgs-msg:quality instead.")
  (quality m))

(cl:ensure-generic-function 'improved-val :lambda-list '(m))
(cl:defmethod improved-val ((m <AdjustGraspResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:improved-val is deprecated.  Use sr_grasp_msgs-msg:improved instead.")
  (improved m))

(cl:ensure-generic-function 'object-val :lambda-list '(m))
(cl:defmethod object-val ((m <AdjustGraspResult>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:object-val is deprecated.  Use sr_grasp_msgs-msg:object instead.")
  (object m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AdjustGraspResult>) ostream)
  "Serializes a message object of type '<AdjustGraspResult>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'quality) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'improved) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'object)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AdjustGraspResult>) istream)
  "Deserializes a message object of type '<AdjustGraspResult>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'quality) istream)
    (cl:setf (cl:slot-value msg 'improved) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'object)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AdjustGraspResult>)))
  "Returns string type for a message object of type '<AdjustGraspResult>"
  "sr_grasp_msgs/AdjustGraspResult")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AdjustGraspResult)))
  "Returns string type for a message object of type 'AdjustGraspResult"
  "sr_grasp_msgs/AdjustGraspResult")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AdjustGraspResult>)))
  "Returns md5sum for a message object of type '<AdjustGraspResult>"
  "77ae0d591df06121a56df6bcdfcb2017")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AdjustGraspResult)))
  "Returns md5sum for a message object of type 'AdjustGraspResult"
  "77ae0d591df06121a56df6bcdfcb2017")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AdjustGraspResult>)))
  "Returns full string definition for message of type '<AdjustGraspResult>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# Result~%KCL_GraspQuality quality~%bool improved~%uint8 object~%~%================================================================================~%MSG: sr_grasp_msgs/KCL_GraspQuality~%# All 3D vectors are referenced in the fingertip core center~%~%Header header					# stamp~%geometry_msgs/Vector3 resultant_force  		# Resultant Force~%geometry_msgs/Vector3 resultant_torque      	# Resultant Torque~%float64[] hull_force_dist			# distances from force hull surface to origin in each octant~%float64[] hull_torque_dist			# distances from force hull surface to origin in each octant~%float64 hull_volume_force			# volume of force hull. basically the grasp quality. unitless.~%float64 hull_volume_torque			# volume of torque hull~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AdjustGraspResult)))
  "Returns full string definition for message of type 'AdjustGraspResult"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# Result~%KCL_GraspQuality quality~%bool improved~%uint8 object~%~%================================================================================~%MSG: sr_grasp_msgs/KCL_GraspQuality~%# All 3D vectors are referenced in the fingertip core center~%~%Header header					# stamp~%geometry_msgs/Vector3 resultant_force  		# Resultant Force~%geometry_msgs/Vector3 resultant_torque      	# Resultant Torque~%float64[] hull_force_dist			# distances from force hull surface to origin in each octant~%float64[] hull_torque_dist			# distances from force hull surface to origin in each octant~%float64 hull_volume_force			# volume of force hull. basically the grasp quality. unitless.~%float64 hull_volume_torque			# volume of torque hull~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AdjustGraspResult>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'quality))
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AdjustGraspResult>))
  "Converts a ROS message object to a list"
  (cl:list 'AdjustGraspResult
    (cl:cons ':quality (quality msg))
    (cl:cons ':improved (improved msg))
    (cl:cons ':object (object msg))
))
