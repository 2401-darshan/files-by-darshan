import React from 'react'
import Navbar from './Navbar';
import Footer from './Footer';
import '../css/signup.css';
import { Link } from 'react-router-dom';

function Signup() {
    return (
        <>
            <Navbar />
            <div className="signup-page">
                <div className="signup-container row mt-5">
                    {/* <!-- Left Section --> */}
                    <div className="col-md-6 signup-left p-5 d-flex flex-column justify-content-center">
                        <h2>Sign Up</h2>
                        <p>Get your free Open Library card and borrow digital books from the nonprofit Internet Archive</p>
                    </div>

                    {/* <!-- Right Section --> */}
                    <div className="col-md-6 signup-right p-5">
                        {/* Google Sign In */}
                        <button className="btn btn-google w-100 mb-3 d-flex align-items-center justify-content-center gap-2">
                            <img src="google.png" alt="Google" style={{ width: "20px", height: "20px" }} />
                            <span>Sign in with Google</span>
                        </button>

                        <div className="or-divider my-4">OR</div>

                        {/* Form */}
                        <form>
                            <div className="mb-3">
                                <label for="email" className="form-label fw-bold">Email</label>
                                <input type="email" className="form-control" id="email" required />
                            </div>

                            <div className="mb-3">
                                <label for="screenName" className="form-label fw-bold">Screen Name</label>
                                <div className="form-text">Public and cannot be changed later.</div>
                                <input type="text" className="form-control" id="screenName" required />
                                <div className="form-text">Your URL: https://openlibrary.org/people/screenname</div>
                            </div>

                            <div className="mb-3">
                                <label for="password" className="form-label fw-bold">Password</label>
                                <div className="input-group">
                                    <input type="password" className="form-control" id="password" required />
                                    <span className="input-group-text"><i className="bi bi-eye-slash"></i></span>
                                </div>
                            </div>

                            <div className="form-check mb-2">
                                <input className="form-check-input" type="checkbox" id="newsCheck" />
                                <label className="form-check-label" for="newsCheck">
                                    I want to receive news, announcements, and resources from the <Link to="#">Internet Archive</Link>, the
                                    nonprofit that runs Open Library.
                                </label>
                            </div>

                            <div className="form-check mb-3">
                                <input className="form-check-input" type="checkbox" id="disabilityCheck" />
                                <label className="form-check-label" for="disabilityCheck">
                                    I want to apply for <Link to="#">special print disability access</Link> through a qualifying program.
                                </label>
                            </div>

                            <button type="submit" className="btn btn-primary w-100 ms-1 mb-3">Sign Up with Email</button>
                            <small className="d-block text-center">
                                By signing up, you agree to the Internet Archive’s <Link to="#">Terms of Service</Link>.
                            </small>
                        </form>

                        <p className="mt-3 text-center">Already have an account? <Link to="/login">Log in</Link></p>
                    </div>
                </div>
            </div>

            <Footer />
        </>
    )
}

export default Signup;
