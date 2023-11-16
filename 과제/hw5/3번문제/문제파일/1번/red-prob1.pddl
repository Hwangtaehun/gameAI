;; problem file: red-prob1.pddl

(define (problem red-prob1)
    (:domain redridinghood)
    (:objects home grannyhouse woods red granny wolf wine)
    (:init (at red home) (have red wine)  
           (at wolf woods) (path_know wolf)
           (at granny grannyhouse)
           (forward red home) (forward red woods) (forward grannyhouse)
           (forward wolf woods) (forward wolf grannyhouse)
           (forward home woods) (forward wood grannyhouse))  
    (:goal (and (path_know red))))