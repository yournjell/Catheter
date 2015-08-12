; Auto-generated. Do not edit!


(cl:in-package sr_grasp_msgs-srv)


;//! \htmlinclude KCL_PoseCorrection-request.msg.html

(cl:defclass <KCL_PoseCorrection-request> (roslisp-msg-protocol:ros-message)
  ((model_id
    :reader model_id
    :initarg :model_id
    :type cl:integer
    :initform 0)
   (mesh
    :reader mesh
    :initarg :mesh
    :type shape_msgs-msg:Mesh
    :initform (cl:make-instance 'shape_msgs-msg:Mesh))
   (initial_pose
    :reader initial_pose
    :initarg :initial_pose
    :type geometry_msgs-msg:PoseStamped
    :initform (cl:make-instance 'geometry_msgs-msg:PoseStamped)))
)

(cl:defclass KCL_PoseCorrection-request (<KCL_PoseCorrection-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <KCL_PoseCorrection-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'KCL_PoseCorrection-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sr_grasp_msgs-srv:<KCL_PoseCorrection-request> is deprecated: use sr_grasp_msgs-srv:KCL_PoseCorrection-request instead.")))

(cl:ensure-generic-function 'model_id-val :lambda-list '(m))
(cl:defmethod model_id-val ((m <KCL_PoseCorrection-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-srv:model_id-val is deprecated.  Use sr_grasp_msgs-srv:model_id instead.")
  (model_id m))

(cl:ensure-generic-function 'mesh-val :lambda-list '(m))
(cl:defmethod mesh-val ((m <KCL_PoseCorrection-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-srv:mesh-val is deprecated.  Use sr_grasp_msgs-srv:mesh instead.")
  (mesh m))

(cl:ensure-generic-function 'initial_pose-val :lambda-list '(m))
(cl:defmethod initial_pose-val ((m <KCL_PoseCorrection-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-srv:initial_pose-val is deprecated.  Use sr_grasp_msgs-srv:initial_pose instead.")
  (initial_pose m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <KCL_PoseCorrection-request>) ostream)
  "Serializes a message object of type '<KCL_PoseCorrection-request>"
  (cl:let* ((signed (cl:slot-value msg 'model_id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'mesh) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'initial_pose) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <KCL_PoseCorrection-request>) istream)
  "Deserializes a message object of type '<KCL_PoseCorrection-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'model_id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'mesh) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'initial_pose) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<KCL_PoseCorrection-request>)))
  "Returns string type for a service object of type '<KCL_PoseCorrection-request>"
  "sr_grasp_msgs/KCL_PoseCorrectionRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'KCL_PoseCorrection-request)))
  "Returns string type for a service object of type 'KCL_PoseCorrection-request"
  "sr_grasp_msgs/KCL_PoseCorrectionRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<KCL_PoseCorrection-request>)))
  "Returns md5sum for a message object of type '<KCL_PoseCorrection-request>"
  "6f6f28b543f31ba5c3ddd26676eb9bb8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'KCL_PoseCorrection-request)))
  "Returns md5sum for a message object of type 'KCL_PoseCorrection-request"
  "6f6f28b543f31ba5c3ddd26676eb9bb8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<KCL_PoseCorrection-request>)))
  "Returns full string definition for message of type '<KCL_PoseCorrection-request>"
  (cl:format cl:nil "~%int32 model_id~%shape_msgs/Mesh mesh~%geometry_msgs/PoseStamped initial_pose~%~%================================================================================~%MSG: shape_msgs/Mesh~%# Definition of a mesh~%~%# list of triangles; the index values refer to positions in vertices[]~%MeshTriangle[] triangles~%~%# the actual vertices that make up the mesh~%geometry_msgs/Point[] vertices~%~%================================================================================~%MSG: shape_msgs/MeshTriangle~%# Definition of a triangle's vertices~%uint32[3] vertex_indices~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/PoseStamped~%# A Pose with reference coordinate frame and timestamp~%Header header~%Pose pose~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of postion and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'KCL_PoseCorrection-request)))
  "Returns full string definition for message of type 'KCL_PoseCorrection-request"
  (cl:format cl:nil "~%int32 model_id~%shape_msgs/Mesh mesh~%geometry_msgs/PoseStamped initial_pose~%~%================================================================================~%MSG: shape_msgs/Mesh~%# Definition of a mesh~%~%# list of triangles; the index values refer to positions in vertices[]~%MeshTriangle[] triangles~%~%# the actual vertices that make up the mesh~%geometry_msgs/Point[] vertices~%~%================================================================================~%MSG: shape_msgs/MeshTriangle~%# Definition of a triangle's vertices~%uint32[3] vertex_indices~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/PoseStamped~%# A Pose with reference coordinate frame and timestamp~%Header header~%Pose pose~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of postion and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <KCL_PoseCorrection-request>))
  (cl:+ 0
     4
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'mesh))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'initial_pose))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <KCL_PoseCorrection-request>))
  "Converts a ROS message object to a list"
  (cl:list 'KCL_PoseCorrection-request
    (cl:cons ':model_id (model_id msg))
    (cl:cons ':mesh (mesh msg))
    (cl:cons ':initial_pose (initial_pose msg))
))
;//! \htmlinclude KCL_PoseCorrection-response.msg.html

(cl:defclass <KCL_PoseCorrection-response> (roslisp-msg-protocol:ros-message)
  ((rect_pose
    :reader rect_pose
    :initarg :rect_pose
    :type geometry_msgs-msg:PoseStamped
    :initform (cl:make-instance 'geometry_msgs-msg:PoseStamped))
   (confidence
    :reader confidence
    :initarg :confidence
    :type std_msgs-msg:Float64
    :initform (cl:make-instance 'std_msgs-msg:Float64))
   (reply
    :reader reply
    :initarg :reply
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass KCL_PoseCorrection-response (<KCL_PoseCorrection-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <KCL_PoseCorrection-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'KCL_PoseCorrection-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sr_grasp_msgs-srv:<KCL_PoseCorrection-response> is deprecated: use sr_grasp_msgs-srv:KCL_PoseCorrection-response instead.")))

(cl:ensure-generic-function 'rect_pose-val :lambda-list '(m))
(cl:defmethod rect_pose-val ((m <KCL_PoseCorrection-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-srv:rect_pose-val is deprecated.  Use sr_grasp_msgs-srv:rect_pose instead.")
  (rect_pose m))

(cl:ensure-generic-function 'confidence-val :lambda-list '(m))
(cl:defmethod confidence-val ((m <KCL_PoseCorrection-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-srv:confidence-val is deprecated.  Use sr_grasp_msgs-srv:confidence instead.")
  (confidence m))

(cl:ensure-generic-function 'reply-val :lambda-list '(m))
(cl:defmethod reply-val ((m <KCL_PoseCorrection-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sr_grasp_msgs-srv:reply-val is deprecated.  Use sr_grasp_msgs-srv:reply instead.")
  (reply m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <KCL_PoseCorrection-response>) ostream)
  "Serializes a message object of type '<KCL_PoseCorrection-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'rect_pose) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'confidence) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'reply) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <KCL_PoseCorrection-response>) istream)
  "Deserializes a message object of type '<KCL_PoseCorrection-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'rect_pose) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'confidence) istream)
    (cl:setf (cl:slot-value msg 'reply) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<KCL_PoseCorrection-response>)))
  "Returns string type for a service object of type '<KCL_PoseCorrection-response>"
  "sr_grasp_msgs/KCL_PoseCorrectionResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'KCL_PoseCorrection-response)))
  "Returns string type for a service object of type 'KCL_PoseCorrection-response"
  "sr_grasp_msgs/KCL_PoseCorrectionResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<KCL_PoseCorrection-response>)))
  "Returns md5sum for a message object of type '<KCL_PoseCorrection-response>"
  "6f6f28b543f31ba5c3ddd26676eb9bb8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'KCL_PoseCorrection-response)))
  "Returns md5sum for a message object of type 'KCL_PoseCorrection-response"
  "6f6f28b543f31ba5c3ddd26676eb9bb8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<KCL_PoseCorrection-response>)))
  "Returns full string definition for message of type '<KCL_PoseCorrection-response>"
  (cl:format cl:nil "~%geometry_msgs/PoseStamped rect_pose~%std_msgs/Float64 confidence~%bool reply~%~%~%~%================================================================================~%MSG: geometry_msgs/PoseStamped~%# A Pose with reference coordinate frame and timestamp~%Header header~%Pose pose~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of postion and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: std_msgs/Float64~%float64 data~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'KCL_PoseCorrection-response)))
  "Returns full string definition for message of type 'KCL_PoseCorrection-response"
  (cl:format cl:nil "~%geometry_msgs/PoseStamped rect_pose~%std_msgs/Float64 confidence~%bool reply~%~%~%~%================================================================================~%MSG: geometry_msgs/PoseStamped~%# A Pose with reference coordinate frame and timestamp~%Header header~%Pose pose~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of postion and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: std_msgs/Float64~%float64 data~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <KCL_PoseCorrection-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'rect_pose))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'confidence))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <KCL_PoseCorrection-response>))
  "Converts a ROS message object to a list"
  (cl:list 'KCL_PoseCorrection-response
    (cl:cons ':rect_pose (rect_pose msg))
    (cl:cons ':confidence (confidence msg))
    (cl:cons ':reply (reply msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'KCL_PoseCorrection)))
  'KCL_PoseCorrection-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'KCL_PoseCorrection)))
  'KCL_PoseCorrection-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'KCL_PoseCorrection)))
  "Returns string type for a service object of type '<KCL_PoseCorrection>"
  "sr_grasp_msgs/KCL_PoseCorrection")