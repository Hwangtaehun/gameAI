;; problem file: red-prob1.pddl

(define (problem red-prob1)
    (:domain redridinghood)
    (:objects home grannyhouse woods red granny wolf huntsman wine flower)
    (:init (alive red) (alive granny) (alive wolf)
           (at red home) (have red wine) (like red flower)
           (at wolf woods) (path_know wolf) (stop wolf)
           (at granny grannyhouse) (at huntsman grannyhouse)
           (forward red home) (forward red woods) (forward red grannyhouse)
           (forward wolf woods) (forward wolf grannyhouse)
           (forward home woods) (forward wood grannyhouse))  
    (:goal (and (have red flower) (eaten red) (at red grannyhouse) (eaten granny) (not (hungry wolf)) (checked huntsman))))