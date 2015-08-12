; Auto-generated. Do not edit!


(cl:in-package sr_grasp_msgs-msg)


;//! \htmlinclude KCL_ContactStateStamped.msg.html

(cl:defclass <KCL_ContactStateStamped> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (tangential_force
    :reader tangential_force
    :initarg :tangential_force
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (contact_position
    :reader contact_position
    :initarg :contact_position
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (contact_normal
    :reader contact_normal
    :initarg :contact_normal
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (Fnormal
    :reader Fnormal
    :initarg :Fnormal
    :type cl:float
    :initform 0.0)
   (Ltorque
    :reader Ltorque
    :initarg :Ltorque
    :type cl:float
    :initform 0.0))
)

(cl:defclass KCL_ContactStateStamped (<KCL_ContactStateStamped>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <KCL_ContactStateStamped>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'KCL_ContactStateStamped)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sr_grasp_msgs-msg:<KCL_ContactStateStamped> is deprecated: use sr_grasp_msgs-msg:KCL_ContactStateStamped instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <KCL_ContactStateStamped>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:header-val is deprecated.  Use sr_grasp_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'tangential_force-val :lambda-list '(m))
(cl:defmethod tangential_force-val ((m <KCL_ContactStateStamped>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:tangential_force-val is deprecated.  Use sr_grasp_msgs-msg:tangential_force instead.")
  (tangential_force m))

(cl:ensure-generic-function 'contact_position-val :lambda-list '(m))
(cl:defmethod contact_position-val ((m <KCL_ContactStateStamped>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:contact_position-val is deprecated.  Use sr_grasp_msgs-msg:contact_position instead.")
  (contact_position m))

(cl:ensure-generic-function 'contact_normal-val :lambda-list '(m))
(cl:defmethod contact_normal-val ((m <KCL_ContactStateStamped>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:contact_normal-val is deprecated.  Use sr_grasp_msgs-msg:contact_normal instead.")
  (contact_normal m))

(cl:ensure-generic-function 'Fnormal-val :lambda-list '(m))
(cl:defmethod Fnormal-val ((m <KCL_ContactStateStamped>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:Fnormal-val is deprecated.  Use sr_grasp_msgs-msg:Fnormal instead.")
  (Fnormal m))

(cl:ensure-generic-function 'Ltorque-val :lambda-list '(m))
(cl:defmethod Ltorque-val ((m <KCL_ContactStateStamped>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:Ltorque-val is deprecated.  Use sr_grasp_msgs-msg:Ltorque instead.")
  (Ltorque m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <KCL_ContactStateStamped>) ostream)
  "Serializes a message object of type '<KCL_ContactStateStamped>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'tangential_force) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'contact_position) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'contact_normal) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Fnormal))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Ltorque))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <KCL_ContactStateStamped>) istream)
  "Deserializes a message object of type '<KCL_ContactStateStamped>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'tangential_force) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'contact_position) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'contact_normal) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Fnormal) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Ltorque) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<KCL_ContactStateStamped>)))
  "Returns string type for a message object of type '<KCL_ContactStateStamped>"
  "sr_grasp_msgs/KCL_ContactStateStamped")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'KCL_ContactStateStamped)))
  "Returns string type for a message object of type 'KCL_ContactStateStamped"
  "sr_grasp_msgs/KCL_ContactStateStamped")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<KCL_ContactStateStamped>)))
  "Returns md5sum for a message object of type '<KCL_ContactStateStamped>"
  "a0f0d461efe98dfada1d88584c069890")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'KCL_ContactStateStamped)))
  "Returns md5sum for a message object of type 'KCL_ContactStateStamped"
  "a0f0d461efe98dfada1d88584c069890")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<KCL_ContactStateStamped>)))
  "Returns full string definition for message of type '<KCL_ContactStateStamped>"
  (cl:format cl:nil "# All 3D vectors are referenced in the fingertip core center~%~%Header header					# stamp~%geometry_msgs/Vector3 tangential_force  	# tangential force (local shear force)~%geometry_msgs/Point  contact_position		# contact position~%geometry_msgs/Vector3 contact_normal      	# contact normal~%float64 Fnormal					# amplitude of normal force (along normal)~%float64 Ltorque					# amplitude of local torque (around normal)~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'KCL_ContactStateStamped)))
  "Returns full string definition for message of type 'KCL_ContactStateStamped"
  (cl:format cl:nil "# All 3D vectors are referenced in the fingertip core center~%~%Header header					# stamp~%geometry_msgs/Vector3 tangential_force  	# tangential force (local shear force)~%geometry_msgs/Point  contact_position		# contact position~%geometry_msgs/Vector3 contact_normal      	# contact normal~%float64 Fnormal					# amplitude of normal force (along normal)~%float64 Ltorque					# amplitude of local torque (around normal)~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <KCL_ContactStateStamped>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'tangential_force))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'contact_position))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'contact_normal))
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <KCL_ContactStateStamped>))
  "Converts a ROS message object to a list"
  (cl:list 'KCL_ContactStateStamped
    (cl:cons ':header (header msg))
    (cl:cons ':tangential_force (tangential_force msg))
    (cl:cons ':contact_position (contact_position msg))
    (cl:cons ':contact_normal (contact_normal msg))
    (cl:cons ':Fnormal (Fnormal msg))
    (cl:cons ':Ltorque (Ltorque msg))
))
