
// int temperature(int time){
//     rertun 1/time;
//     }

// int* neighbour(initial_state){

// }

// int* SportsLayout::simulated_annealing(){
//     int* initial state = SportsLayout::random_mapping();
//     while(1){
//         int* next_state = SportsLayout::random_mapping();
//         if(temperature(time) < 0.0001){
//             return initial_state;
//         }
//         if(SportsLayout::neighbour_cost_fn(next_state) < SportsLayout::neighbour_cost_fn(initial_state)){
//             initial_state = next_state;
//         }
//         else{
//             if(exp((SportsLayout::cost(initial_state) - SportsLayout::cost(next_state))/temperature(time)) > rand()){
//                 initial_state = next_state;
//             }
//         }
//     }
// }
