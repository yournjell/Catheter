; Auto-generated. Do not edit!


(cl:in-package sr_grasp_msgs-msg)


;//! \htmlinclude KCL_GraspQuality.msg.html

(cl:defclass <KCL_GraspQuality> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (resultant_force
    :reader resultant_force
    :initarg :resultant_force
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (resultant_torque
    :reader resultant_torque
    :initarg :resultant_torque
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (hull_force_dist
    :reader hull_force_dist
    :initarg :hull_force_dist
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (hull_torque_dist
    :reader hull_torque_dist
    :initarg :hull_torque_dist
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (hull_volume_force
    :reader hull_volume_force
    :initarg :hull_volume_force
    :type cl:float
    :initform 0.0)
   (hull_volume_torque
    :reader hull_volume_torque
    :initarg :hull_volume_torque
    :type cl:float
    :initform 0.0))
)

(cl:defclass KCL_GraspQuality (<KCL_GraspQuality>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <KCL_GraspQuality>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'KCL_GraspQuality)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sr_grasp_msgs-msg:<KCL_GraspQuality> is deprecated: use sr_grasp_msgs-msg:KCL_GraspQuality instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <KCL_GraspQuality>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:header-val is deprecated.  Use sr_grasp_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'resultant_force-val :lambda-list '(m))
(cl:defmethod resultant_force-val ((m <KCL_GraspQuality>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:resultant_force-val is deprecated.  Use sr_grasp_msgs-msg:resultant_force instead.")
  (resultant_force m))

(cl:ensure-generic-function 'resultant_torque-val :lambda-list '(m))
(cl:defmethod resultant_torque-val ((m <KCL_GraspQuality>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:resultant_torque-val is deprecated.  Use sr_grasp_msgs-msg:resultant_torque instead.")
  (resultant_torque m))

(cl:ensure-generic-function 'hull_force_dist-val :lambda-list '(m))
(cl:defmethod hull_force_dist-val ((m <KCL_GraspQuality>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:hull_force_dist-val is deprecated.  Use sr_grasp_msgs-msg:hull_force_dist instead.")
  (hull_force_dist m))

(cl:ensure-generic-function 'hull_torque_dist-val :lambda-list '(m))
(cl:defmethod hull_torque_dist-val ((m <KCL_GraspQuality>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:hull_torque_dist-val is deprecated.  Use sr_grasp_msgs-msg:hull_torque_dist instead.")
  (hull_torque_dist m))

(cl:ensure-generic-function 'hull_volume_force-val :lambda-list '(m))
(cl:defmethod hull_volume_force-val ((m <KCL_GraspQuality>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:hull_volume_force-val is deprecated.  Use sr_grasp_msgs-msg:hull_volume_force instead.")
  (hull_volume_force m))

(cl:ensure-generic-function 'hull_volume_torque-val :lambda-list '(m))
(cl:defmethod hull_volume_torque-val ((m <KCL_GraspQuality>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:hull_volume_torque-val is deprecated.  Use sr_grasp_msgs-msg:hull_volume_torque instead.")
  (hull_volume_torque m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <KCL_GraspQuality>) ostream)
  "Serializes a message object of type '<KCL_GraspQuality>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'resultant_force) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'resultant_torque) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'hull_force_dist))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'hull_force_dist))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'hull_torque_dist))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'hull_torque_dist))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'hull_volume_force))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'hull_volume_torque))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <KCL_GraspQuality>) istream)
  "Deserializes a message object of type '<KCL_GraspQuality>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'resultant_force) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'resultant_torque) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'hull_force_dist) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'hull_force_dist)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'hull_torque_dist) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'hull_torque_dist)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits))))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'hull_volume_force) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'hull_volume_torque) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<KCL_GraspQuality>)))
  "Returns string type for a message object of type '<KCL_GraspQuality>"
  "sr_grasp_msgs/KCL_GraspQuality")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'KCL_GraspQuality)))
  "Returns string type for a message object of type 'KCL_GraspQuality"
  "sr_grasp_msgs/KCL_GraspQuality")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<KCL_GraspQuality>)))
  "Returns md5sum for a message object of type '<KCL_GraspQuality>"
  "6c8ff29bdbd0865512357a0c247906ca")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'KCL_GraspQuality)))
  "Returns md5sum for a message object of type 'KCL_GraspQuality"
  "6c8ff29bdbd0865512357a0c247906ca")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<KCL_GraspQuality>)))
  "Returns full string definition for message of type '<KCL_GraspQuality>"
  (cl:format cl:nil "# All 3D vectors are referenced in the fingertip core center~%~%Header header					# stamp~%geometry_msgs/Vector3 resultant_force  		# Resultant Force~%geometry_msgs/Vector3 resultant_torque      	# Resultant Torque~%float64[] hull_force_dist			# distances from force hull surface to origin in each octant~%float64[] hull_torque_dist			# distances from force hull surface to origin in each octant~%float64 hull_volume_force			# volume of force hull. basically the grasp quality. unitless.~%float64 hull_volume_torque			# volume of torque hull~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'KCL_GraspQuality)))
  "Returns full string definition for message of type 'KCL_GraspQuality"
  (cl:format cl:nil "# All 3D vectors are referenced in the fingertip core center~%~%Header header					# stamp~%geometry_msgs/Vector3 resultant_force  		# Resultant Force~%geometry_msgs/Vector3 resultant_torque      	# Resultant Torque~%float64[] hull_force_dist			# distances from force hull surface to origin in each octant~%float64[] hull_torque_dist			# distances from force hull surface to origin in each octant~%float64 hull_volume_force			# volume of force hull. basically the grasp quality. unitless.~%float64 hull_volume_torque			# volume of torque hull~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <KCL_GraspQuality>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'resultant_force))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'resultant_torque))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'hull_force_dist) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'hull_torque_dist) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <KCL_GraspQuality>))
  "Converts a ROS message object to a list"
  (cl:list 'KCL_GraspQuality
    (cl:cons ':header (header msg))
    (cl:cons ':resultant_force (resultant_force msg))
    (cl:cons ':resultant_torque (resultant_torque msg))
    (cl:cons ':hull_force_dist (hull_force_dist msg))
    (cl:cons ':hull_torque_dist (hull_torque_dist msg))
    (cl:cons ':hull_volume_force (hull_volume_force msg))
    (cl:cons ':hull_volume_torque (hull_volume_torque msg))
))
