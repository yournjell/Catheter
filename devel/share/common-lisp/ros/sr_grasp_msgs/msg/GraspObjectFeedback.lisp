; Auto-generated. Do not edit!


(cl:in-package sr_grasp_msgs-msg)


;//! \htmlinclude GraspObjectFeedback.msg.html

(cl:defclass <GraspObjectFeedback> (roslisp-msg-protocol:ros-message)
  ((state
    :reader state
    :initarg :state
    :type cl:fixnum
    :initform 0)
   (quality
    :reader quality
    :initarg :quality
    :type cl:float
    :initform 0.0)
   (distance
    :reader distance
    :initarg :distance
    :type cl:float
    :initform 0.0))
)

(cl:defclass GraspObjectFeedback (<GraspObjectFeedback>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GraspObjectFeedback>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GraspObjectFeedback)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sr_grasp_msgs-msg:<GraspObjectFeedback> is deprecated: use sr_grasp_msgs-msg:GraspObjectFeedback instead.")))

(cl:ensure-generic-function 'state-val :lambda-list '(m))
(cl:defmethod state-val ((m <GraspObjectFeedback>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:state-val is deprecated.  Use sr_grasp_msgs-msg:state instead.")
  (state m))

(cl:ensure-generic-function 'quality-val :lambda-list '(m))
(cl:defmethod quality-val ((m <GraspObjectFeedback>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:quality-val is deprecated.  Use sr_grasp_msgs-msg:quality instead.")
  (quality m))

(cl:ensure-generic-function 'distance-val :lambda-list '(m))
(cl:defmethod distance-val ((m <GraspObjectFeedback>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:distance-val is deprecated.  Use sr_grasp_msgs-msg:distance instead.")
  (distance m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<GraspObjectFeedback>)))
    "Constants for message type '<GraspObjectFeedback>"
  '((:TRACKING . 0)
    (:GRABBING . 1)
    (:STABILISING . 2)
    (:RELEASING . 3))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'GraspObjectFeedback)))
    "Constants for message type 'GraspObjectFeedback"
  '((:TRACKING . 0)
    (:GRABBING . 1)
    (:STABILISING . 2)
    (:RELEASING . 3))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GraspObjectFeedback>) ostream)
  "Serializes a message object of type '<GraspObjectFeedback>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'state)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'quality))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'distance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GraspObjectFeedback>) istream)
  "Deserializes a message object of type '<GraspObjectFeedback>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'state)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'quality) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'distance) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GraspObjectFeedback>)))
  "Returns string type for a message object of type '<GraspObjectFeedback>"
  "sr_grasp_msgs/GraspObjectFeedback")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GraspObjectFeedback)))
  "Returns string type for a message object of type 'GraspObjectFeedback"
  "sr_grasp_msgs/GraspObjectFeedback")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GraspObjectFeedback>)))
  "Returns md5sum for a message object of type '<GraspObjectFeedback>"
  "619ac7b0276702e8a8dfca3edd8e490c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GraspObjectFeedback)))
  "Returns md5sum for a message object of type 'GraspObjectFeedback"
  "619ac7b0276702e8a8dfca3edd8e490c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GraspObjectFeedback>)))
  "Returns full string definition for message of type '<GraspObjectFeedback>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# Feedback~%# State shows what the node is currently doing.~%uint8 TRACKING=0~%uint8 GRABBING=1~%uint8 STABILISING=2~%uint8 RELEASING=3~%uint8 state~%# A percentage or other measure of the quality of the grasp.~%float64 quality~%# How far away the object is.~%float64 distance~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GraspObjectFeedback)))
  "Returns full string definition for message of type 'GraspObjectFeedback"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# Feedback~%# State shows what the node is currently doing.~%uint8 TRACKING=0~%uint8 GRABBING=1~%uint8 STABILISING=2~%uint8 RELEASING=3~%uint8 state~%# A percentage or other measure of the quality of the grasp.~%float64 quality~%# How far away the object is.~%float64 distance~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GraspObjectFeedback>))
  (cl:+ 0
     1
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GraspObjectFeedback>))
  "Converts a ROS message object to a list"
  (cl:list 'GraspObjectFeedback
    (cl:cons ':state (state msg))
    (cl:cons ':quality (quality msg))
    (cl:cons ':distance (distance msg))
))
