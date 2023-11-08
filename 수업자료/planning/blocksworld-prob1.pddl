;; problem file: blocksword-prob1.pddl

(define (problem blocksword-prob1)
    (:domain blocksworld)
    (:objects a b)
    (:init (on-table a) (on-table b)  
           (clear a) (clear b) (arm-empty))
    (:goal (and (on b a))))