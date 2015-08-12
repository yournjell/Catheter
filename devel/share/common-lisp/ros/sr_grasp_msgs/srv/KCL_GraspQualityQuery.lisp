; Auto-generated. Do not edit!


(cl:in-package sr_grasp_msgs-srv)


;//! \htmlinclude KCL_GraspQualityQuery-request.msg.html

(cl:defclass <KCL_GraspQualityQuery-request> (roslisp-msg-protocol:ros-message)
  ((contacts
    :reader contacts
    :initarg :contacts
    :type (cl:vector sr_grasp_msgs-msg:KCL_ContactStateStamped)
   :initform (cl:make-array 0 :element-type 'sr_grasp_msgs-msg:KCL_ContactStateStamped :initial-element (cl:make-instance 'sr_grasp_msgs-msg:KCL_ContactStateStamped)))
   (centre_of_mass
    :reader centre_of_mass
    :initarg :centre_of_mass
    :type geometry_msgs-msg:PointStamped
    :initform (cl:make-instance 'geometry_msgs-msg:PointStamped)))
)

(cl:defclass KCL_GraspQualityQuery-request (<KCL_GraspQualityQuery-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <KCL_GraspQualityQuery-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'KCL_GraspQualityQuery-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sr_grasp_msgs-srv:<KCL_GraspQualityQuery-request> is deprecated: use sr_grasp_msgs-srv:KCL_GraspQualityQuery-request instead.")))

(cl:ensure-generic-function 'contacts-val :lambda-list '(m))
(cl:defmethod contacts-val ((m <KCL_GraspQualityQuery-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-srv:contacts-val is deprecated.  Use sr_grasp_msgs-srv:contacts instead.")
  (contacts m))

(cl:ensure-generic-function 'centre_of_mass-val :lambda-list '(m))
(cl:defmethod centre_of_mass-val ((m <KCL_GraspQualityQuery-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-srv:centre_of_mass-val is deprecated.  Use sr_grasp_msgs-srv:centre_of_mass instead.")
  (centre_of_mass m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <KCL_GraspQualityQuery-request>) ostream)
  "Serializes a message object of type '<KCL_GraspQualityQuery-request>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'contacts))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'contacts))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'centre_of_mass) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <KCL_GraspQualityQuery-request>) istream)
  "Deserializes a message object of type '<KCL_GraspQualityQuery-request>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'contacts) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'contacts)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'sr_grasp_msgs-msg:KCL_ContactStateStamped))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'centre_of_mass) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<KCL_GraspQualityQuery-request>)))
  "Returns string type for a service object of type '<KCL_GraspQualityQuery-request>"
  "sr_grasp_msgs/KCL_GraspQualityQueryRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'KCL_GraspQualityQuery-request)))
  "Returns string type for a service object of type 'KCL_GraspQualityQuery-request"
  "sr_grasp_msgs/KCL_GraspQualityQueryRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<KCL_GraspQualityQuery-request>)))
  "Returns md5sum for a message object of type '<KCL_GraspQualityQuery-request>"
  "b80430ef87f1ab2ffc18ffe08ba13cb0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'KCL_GraspQualityQuery-request)))
  "Returns md5sum for a message object of type 'KCL_GraspQualityQuery-request"
  "b80430ef87f1ab2ffc18ffe08ba13cb0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<KCL_GraspQualityQuery-request>)))
  "Returns full string definition for message of type '<KCL_GraspQualityQuery-request>"
  (cl:format cl:nil "sr_grasp_msgs/KCL_ContactStateStamped[] contacts~%geometry_msgs/PointStamped centre_of_mass~%~%================================================================================~%MSG: sr_grasp_msgs/KCL_ContactStateStamped~%# All 3D vectors are referenced in the fingertip core center~%~%Header header					# stamp~%geometry_msgs/Vector3 tangential_force  	# tangential force (local shear force)~%geometry_msgs/Point  contact_position		# contact position~%geometry_msgs/Vector3 contact_normal      	# contact normal~%float64 Fnormal					# amplitude of normal force (along normal)~%float64 Ltorque					# amplitude of local torque (around normal)~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/PointStamped~%# This represents a Point with reference coordinate frame and timestamp~%Header header~%Point point~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'KCL_GraspQualityQuery-request)))
  "Returns full string definition for message of type 'KCL_GraspQualityQuery-request"
  (cl:format cl:nil "sr_grasp_msgs/KCL_ContactStateStamped[] contacts~%geometry_msgs/PointStamped centre_of_mass~%~%================================================================================~%MSG: sr_grasp_msgs/KCL_ContactStateStamped~%# All 3D vectors are referenced in the fingertip core center~%~%Header header					# stamp~%geometry_msgs/Vector3 tangential_force  	# tangential force (local shear force)~%geometry_msgs/Point  contact_position		# contact position~%geometry_msgs/Vector3 contact_normal      	# contact normal~%float64 Fnormal					# amplitude of normal force (along normal)~%float64 Ltorque					# amplitude of local torque (around normal)~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/PointStamped~%# This represents a Point with reference coordinate frame and timestamp~%Header header~%Point point~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <KCL_GraspQualityQuery-request>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'contacts) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'centre_of_mass))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <KCL_GraspQualityQuery-request>))
  "Converts a ROS message object to a list"
  (cl:list 'KCL_GraspQualityQuery-request
    (cl:cons ':contacts (contacts msg))
    (cl:cons ':centre_of_mass (centre_of_mass msg))
))
;//! \htmlinclude KCL_GraspQualityQuery-response.msg.html

(cl:defclass <KCL_GraspQualityQuery-response> (roslisp-msg-protocol:ros-message)
  ((quality
    :reader quality
    :initarg :quality
    :type sr_grasp_msgs-msg:KCL_GraspQuality
    :initform (cl:make-instance 'sr_grasp_msgs-msg:KCL_GraspQuality)))
)

(cl:defclass KCL_GraspQualityQuery-response (<KCL_GraspQualityQuery-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <KCL_GraspQualityQuery-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'KCL_GraspQualityQuery-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sr_grasp_msgs-srv:<KCL_GraspQualityQuery-response> is deprecated: use sr_grasp_msgs-srv:KCL_GraspQualityQuery-response instead.")))

(cl:ensure-generic-function 'quality-val :lambda-list '(m))
(cl:defmethod quality-val ((m <KCL_GraspQualityQuery-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-srv:quality-val is deprecated.  Use sr_grasp_msgs-srv:quality instead.")
  (quality m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <KCL_GraspQualityQuery-response>) ostream)
  "Serializes a message object of type '<KCL_GraspQualityQuery-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'quality) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <KCL_GraspQualityQuery-response>) istream)
  "Deserializes a message object of type '<KCL_GraspQualityQuery-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'quality) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<KCL_GraspQualityQuery-response>)))
  "Returns string type for a service object of type '<KCL_GraspQualityQuery-response>"
  "sr_grasp_msgs/KCL_GraspQualityQueryResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'KCL_GraspQualityQuery-response)))
  "Returns string type for a service object of type 'KCL_GraspQualityQuery-response"
  "sr_grasp_msgs/KCL_GraspQualityQueryResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<KCL_GraspQualityQuery-response>)))
  "Returns md5sum for a message object of type '<KCL_GraspQualityQuery-response>"
  "b80430ef87f1ab2ffc18ffe08ba13cb0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'KCL_GraspQualityQuery-response)))
  "Returns md5sum for a message object of type 'KCL_GraspQualityQuery-response"
  "b80430ef87f1ab2ffc18ffe08ba13cb0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<KCL_GraspQualityQuery-response>)))
  "Returns full string definition for message of type '<KCL_GraspQualityQuery-response>"
  (cl:format cl:nil "KCL_GraspQuality quality~%~%~%~%================================================================================~%MSG: sr_grasp_msgs/KCL_GraspQuality~%# All 3D vectors are referenced in the fingertip core center~%~%Header header					# stamp~%geometry_msgs/Vector3 resultant_force  		# Resultant Force~%geometry_msgs/Vector3 resultant_torque      	# Resultant Torque~%float64[] hull_force_dist			# distances from force hull surface to origin in each octant~%float64[] hull_torque_dist			# distances from force hull surface to origin in each octant~%float64 hull_volume_force			# volume of force hull. basically the grasp quality. unitless.~%float64 hull_volume_torque			# volume of torque hull~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'KCL_GraspQualityQuery-response)))
  "Returns full string definition for message of type 'KCL_GraspQualityQuery-response"
  (cl:format cl:nil "KCL_GraspQuality quality~%~%~%~%================================================================================~%MSG: sr_grasp_msgs/KCL_GraspQuality~%# All 3D vectors are referenced in the fingertip core center~%~%Header header					# stamp~%geometry_msgs/Vector3 resultant_force  		# Resultant Force~%geometry_msgs/Vector3 resultant_torque      	# Resultant Torque~%float64[] hull_force_dist			# distances from force hull surface to origin in each octant~%float64[] hull_torque_dist			# distances from force hull surface to origin in each octant~%float64 hull_volume_force			# volume of force hull. basically the grasp quality. unitless.~%float64 hull_volume_torque			# volume of torque hull~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <KCL_GraspQualityQuery-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'quality))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <KCL_GraspQualityQuery-response>))
  "Converts a ROS message object to a list"
  (cl:list 'KCL_GraspQualityQuery-response
    (cl:cons ':quality (quality msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'KCL_GraspQualityQuery)))
  'KCL_GraspQualityQuery-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'KCL_GraspQualityQuery)))
  'KCL_GraspQualityQuery-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'KCL_GraspQualityQuery)))
  "Returns string type for a service object of type '<KCL_GraspQualityQuery>"
  "sr_grasp_msgs/KCL_GraspQualityQuery")