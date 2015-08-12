
(cl:in-package :asdf)

(defsystem "sr_grasp_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "KCL_GraspQuality" :depends-on ("_package_KCL_GraspQuality"))
    (:file "_package_KCL_GraspQuality" :depends-on ("_package"))
    (:file "KCL_ContactStateStamped" :depends-on ("_package_KCL_ContactStateStamped"))
    (:file "_package_KCL_ContactStateStamped" :depends-on ("_package"))
    (:file "StabilisationState" :depends-on ("_package_StabilisationState"))
    (:file "_package_StabilisationState" :depends-on ("_package"))
    (:file "StabilisationCommand" :depends-on ("_package_StabilisationCommand"))
    (:file "_package_StabilisationCommand" :depends-on ("_package"))
  ))