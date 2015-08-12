; Auto-generated. Do not edit!


(cl:in-package sr_grasp_msgs-msg)


;//! \htmlinclude StabilisationCommand.msg.html

(cl:defclass <StabilisationCommand> (roslisp-msg-protocol:ros-message)
  ((active
    :reader active
    :initarg :active
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass StabilisationCommand (<StabilisationCommand>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <StabilisationCommand>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'StabilisationCommand)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sr_grasp_msgs-msg:<StabilisationCommand> is deprecated: use sr_grasp_msgs-msg:StabilisationCommand instead.")))

(cl:ensure-generic-function 'active-val :lambda-list '(m))
(cl:defmethod active-val ((m <StabilisationCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-msg:active-val is deprecated.  Use sr_grasp_msgs-msg:active instead.")
  (active m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <StabilisationCommand>) ostream)
  "Serializes a message object of type '<StabilisationCommand>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'active) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <StabilisationCommand>) istream)
  "Deserializes a message object of type '<StabilisationCommand>"
    (cl:setf (cl:slot-value msg 'active) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<StabilisationCommand>)))
  "Returns string type for a message object of type '<StabilisationCommand>"
  "sr_grasp_msgs/StabilisationCommand")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StabilisationCommand)))
  "Returns string type for a message object of type 'StabilisationCommand"
  "sr_grasp_msgs/StabilisationCommand")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<StabilisationCommand>)))
  "Returns md5sum for a message object of type '<StabilisationCommand>"
  "2c5cfb0a2565df41de6873994aee57d2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'StabilisationCommand)))
  "Returns md5sum for a message object of type 'StabilisationCommand"
  "2c5cfb0a2565df41de6873994aee57d2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<StabilisationCommand>)))
  "Returns full string definition for message of type '<StabilisationCommand>"
  (cl:format cl:nil "# Command the stabilisation controller.~%# Just turn it off and on for now, we get fleshed out over time.~%bool active~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'StabilisationCommand)))
  "Returns full string definition for message of type 'StabilisationCommand"
  (cl:format cl:nil "# Command the stabilisation controller.~%# Just turn it off and on for now, we get fleshed out over time.~%bool active~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <StabilisationCommand>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <StabilisationCommand>))
  "Converts a ROS message object to a list"
  (cl:list 'StabilisationCommand
    (cl:cons ':active (active msg))
))
