; Auto-generated. Do not edit!


(cl:in-package sr_grasp_msgs-msg)


;//! \htmlinclude ForceControlFeedback.msg.html

(cl:defclass <ForceControlFeedback> (roslisp-msg-protocol:ros-message)
  ((current_state
    :reader current_state
    :initarg :current_state
    :type cl:float
    :initform 0.0)
   (normal
    :reader normal
    :initarg :normal
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3))
   (tangential
    :reader tangential
    :initarg :tangential
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3)))
)

(cl:defclass ForceControlFeedback (<ForceControlFeedback>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ForceControlFeedback>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ForceControlFeedback)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sr_grasp_msgs-msg:<ForceControlFeedback> is deprecated: use sr_grasp_msgs-msg:ForceControlFeedback instead.")))

(cl:ensure-generic-function 'current_state-val :lambda-list '(m))
(cl:defmethod current_state-val ((m <ForceControlFeedback>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:current_state-val is deprecated.  Use sr_grasp_msgs-msg:current_state instead.")
  (current_state m))

(cl:ensure-generic-function 'normal-val :lambda-list '(m))
(cl:defmethod normal-val ((m <ForceControlFeedback>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:normal-val is deprecated.  Use sr_grasp_msgs-msg:normal instead.")
  (normal m))

(cl:ensure-generic-function 'tangential-val :lambda-list '(m))
(cl:defmethod tangential-val ((m <ForceControlFeedback>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:tangential-val is deprecated.  Use sr_grasp_msgs-msg:tangential instead.")
  (tangential m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ForceControlFeedback>) ostream)
  "Serializes a message object of type '<ForceControlFeedback>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'current_state))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'normal) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'tangential) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ForceControlFeedback>) istream)
  "Deserializes a message object of type '<ForceControlFeedback>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'current_state) (roslisp-utils:decode-double-float-bits bits)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'normal) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'tangential) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ForceControlFeedback>)))
  "Returns string type for a message object of type '<ForceControlFeedback>"
  "sr_grasp_msgs/ForceControlFeedback")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ForceControlFeedback)))
  "Returns string type for a message object of type 'ForceControlFeedback"
  "sr_grasp_msgs/ForceControlFeedback")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ForceControlFeedback>)))
  "Returns md5sum for a message object of type '<ForceControlFeedback>"
  "c2c88f3d072d22e6edb0af4767beecd3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ForceControlFeedback)))
  "Returns md5sum for a message object of type 'ForceControlFeedback"
  "c2c88f3d072d22e6edb0af4767beecd3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ForceControlFeedback>)))
  "Returns full string definition for message of type '<ForceControlFeedback>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# Feedback~%# State shows what the node is currently doing.~%float64 current_state #current normal force~%geometry_msgs/Vector3 normal #current normal direction~%geometry_msgs/Vector3 tangential #current tangential direction~%~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ForceControlFeedback)))
  "Returns full string definition for message of type 'ForceControlFeedback"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# Feedback~%# State shows what the node is currently doing.~%float64 current_state #current normal force~%geometry_msgs/Vector3 normal #current normal direction~%geometry_msgs/Vector3 tangential #current tangential direction~%~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ForceControlFeedback>))
  (cl:+ 0
     8
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'normal))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'tangential))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ForceControlFeedback>))
  "Converts a ROS message object to a list"
  (cl:list 'ForceControlFeedback
    (cl:cons ':current_state (current_state msg))
    (cl:cons ':normal (normal msg))
    (cl:cons ':tangential (tangential msg))
))
