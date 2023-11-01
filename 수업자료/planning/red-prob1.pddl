;; problem file: red-prob1.pddl

(define (problem red-prob1)
    (:domain redridinghood)
    (:objects home grannyhouse woods red granny wolf wine)
    (:init (at red home) (have red wine) 
           (alive red) (alive granny) (alive wolf)
           (at wolf woods) (hungry wolf)
           (at granny grannyhouse))  
    (:goal (and (have granny wine) (happy wolf) (not (hungry wolf)) (happy granny))))