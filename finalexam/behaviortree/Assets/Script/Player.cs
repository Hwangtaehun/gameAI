using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public float moveSpeed = 5.0f;
    public float rotationSpeed = 360.0f;
    public float jumpSpeed = 5.0f;
    private CharacterController characterController;
    private float ySpeed;
    private float originalStepOffset;

    void Start()
    {
        characterController = GetComponent<CharacterController>();
    }

    void Update()
    {
        // 좌우 방향키와 상하 방향키를 눌렀는지 판별
        Vector3 direction = new Vector3(Input.GetAxis("Horizontal"), 0, Input.GetAxis("Vertical"));

        //점프
        ySpeed += Physics.gravity.y * Time.deltaTime;
        if (characterController.isGrounded)
        {
            characterController.stepOffset = originalStepOffset;
            ySpeed = -0.5f;

            if (Input.GetButtonDown("Jump"))
            {
                ySpeed = jumpSpeed;
            }
        }
        else
        {
            characterController.stepOffset = 0;
        }

        if (direction.sqrMagnitude > 0.01f)
        {
            Vector3 forward = Vector3.Slerp( // 메소드를 조합해 플레이어의 방향 변환
            transform.forward,
            direction,
            rotationSpeed * Time.deltaTime / Vector3.Angle(transform.forward, direction)
            );
            transform.LookAt(transform.position + forward);
        }

        // Move()를 이용해 이동, 충돌 처리, 속도 값 얻기 가능
        Vector3 velocity = direction * moveSpeed * Time.deltaTime;
        velocity.y = ySpeed * Time.deltaTime;

        characterController.Move(velocity);

        Vector3 horizontalVelocity = characterController.velocity;
        horizontalVelocity = new Vector3(characterController.velocity.x, 0, characterController.velocity.z);
    }
}
