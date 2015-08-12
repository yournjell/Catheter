; Auto-generated. Do not edit!


(cl:in-package sr_grasp_msgs-msg)


;//! \htmlinclude ForceControlGoal.msg.html

(cl:defclass <ForceControlGoal> (roslisp-msg-protocol:ros-message)
  ((set_point_upper
    :reader set_point_upper
    :initarg :set_point_upper
    :type cl:float
    :initform 0.0)
   (set_point_lower
    :reader set_point_lower
    :initarg :set_point_lower
    :type cl:float
    :initform 0.0)
   (start_degree
    :reader start_degree
    :initarg :start_degree
    :type cl:float
    :initform 0.0))
)

(cl:defclass ForceControlGoal (<ForceControlGoal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ForceControlGoal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ForceControlGoal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sr_grasp_msgs-msg:<ForceControlGoal> is deprecated: use sr_grasp_msgs-msg:ForceControlGoal instead.")))

(cl:ensure-generic-function 'set_point_upper-val :lambda-list '(m))
(cl:defmethod set_point_upper-val ((m <ForceControlGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:set_point_upper-val is deprecated.  Use sr_grasp_msgs-msg:set_point_upper instead.")
  (set_point_upper m))

(cl:ensure-generic-function 'set_point_lower-val :lambda-list '(m))
(cl:defmethod set_point_lower-val ((m <ForceControlGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:set_point_lower-val is deprecated.  Use sr_grasp_msgs-msg:set_point_lower instead.")
  (set_point_lower m))

(cl:ensure-generic-function 'start_degree-val :lambda-list '(m))
(cl:defmethod start_degree-val ((m <ForceControlGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:start_degree-val is deprecated.  Use sr_grasp_msgs-msg:start_degree instead.")
  (start_degree m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ForceControlGoal>) ostream)
  "Serializes a message object of type '<ForceControlGoal>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'set_point_upper))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'set_point_lower))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'start_degree))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ForceControlGoal>) istream)
  "Deserializes a message object of type '<ForceControlGoal>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'set_point_upper) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'set_point_lower) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'start_degree) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ForceControlGoal>)))
  "Returns string type for a message object of type '<ForceControlGoal>"
  "sr_grasp_msgs/ForceControlGoal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ForceControlGoal)))
  "Returns string type for a message object of type 'ForceControlGoal"
  "sr_grasp_msgs/ForceControlGoal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ForceControlGoal>)))
  "Returns md5sum for a message object of type '<ForceControlGoal>"
  "d6aabfe1c6f601d99ee7099bd14184b9")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ForceControlGoal)))
  "Returns md5sum for a message object of type 'ForceControlGoal"
  "d6aabfe1c6f601d99ee7099bd14184b9")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ForceControlGoal>)))
  "Returns full string definition for message of type '<ForceControlGoal>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# Force Control.~%# Goal~%float64 set_point_upper #reference normal force up~%float64 set_point_lower #reference normal force down~%float64 start_degree #start_degree at joint 3~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ForceControlGoal)))
  "Returns full string definition for message of type 'ForceControlGoal"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# Force Control.~%# Goal~%float64 set_point_upper #reference normal force up~%float64 set_point_lower #reference normal force down~%float64 start_degree #start_degree at joint 3~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ForceControlGoal>))
  (cl:+ 0
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ForceControlGoal>))
  "Converts a ROS message object to a list"
  (cl:list 'ForceControlGoal
    (cl:cons ':set_point_upper (set_point_upper msg))
    (cl:cons ':set_point_lower (set_point_lower msg))
    (cl:cons ':start_degree (start_degree msg))
))
