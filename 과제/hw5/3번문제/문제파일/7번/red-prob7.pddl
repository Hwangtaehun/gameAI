;; problem file: red-prob1.pddl

(define (problem red-prob1)
    (:domain redridinghood)
    (:objects home grannyhouse woods red granny wolf huntsman wine flower cakes)
    (:init (alive red) (alive granny) (alive wolf) (alive huntsman)
           (at red home) (have red wine) (like red flower) (like red cakes) (errand red)
           (at wolf woods) (path_know wolf) (stop wolf)
           (at granny grannyhouse) (like granny cakes)
           (at huntsman grannyhouse) (like huntsman cakes)
           (forward red home) (forward red woods) (forward red grannyhouse)
           (forward wolf woods) (forward wolf grannyhouse)
           (forward home woods) (forward wood grannyhouse))  
    (:goal (and (have red flower) (happy red) (at red grannyhouse) (eaten red) (eaten granny) (happy granny) (not (hungry wolf)) (not (alive wolf)) (happy huntsman))))