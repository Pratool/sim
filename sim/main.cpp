#include "Simbody.h"

#include <iostream>

int main()
{
    std::cout << "Running simulator." << std::endl;

    SimTK::MultibodySystem system{};
    SimTK::SimbodyMatterSubsystem matter{system};
    SimTK::GeneralForceSubsystem forces(system);

    SimTK::Force::UniformGravity gravity(forces, matter, SimTK::Vec3(0, -9.8, 0));
    SimTK::Body::Rigid pendulumBody(SimTK::MassProperties(1.0, SimTK::Vec3(0), SimTK::Inertia(1)));
    pendulumBody.addDecoration(SimTK::Transform(), SimTK::DecorativeSphere(0.1));
    SimTK::MobilizedBody::Pin pendulum1(matter.Ground(), SimTK::Transform(SimTK::Vec3(0)),
                                        pendulumBody, SimTK::Transform(SimTK::Vec3(0, 1, 0)));
    SimTK::MobilizedBody::Pin pendulum2(pendulum1, SimTK::Transform(SimTK::Vec3(0)),
    pendulumBody, SimTK::Transform(SimTK::Vec3(0, 1, 0)));
    // Set up visualization.
    SimTK::Visualizer viz(system);
    system.addEventReporter(new SimTK::Visualizer::Reporter(viz, 0.01));
    // Initialize the system and state.
    system.realizeTopology();
    SimTK::State state = system.getDefaultState();
    pendulum2.setRate(state, 5.0);
    // Simulate it.
    SimTK::RungeKuttaMersonIntegrator integ(system);
    SimTK::TimeStepper ts(system, integ);
    ts.initialize(state);

    return 0;
}
