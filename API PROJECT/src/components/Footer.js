import React from 'react';
import '../css/footer.css';

function Footer() {
    return (
        <>
            {/* <!-- Footer --> */}
            <footer>
                <div className="container">
                    <div className="row">
                        {/* <!-- Open Library --> */}
                        <div className="col-6 col-md-3">
                            <h6>Open Library</h6>
                            <Link to="#">Vision</Link>
                            <Link to="#">Volunteer</Link>
                            <Link to="#">Partner With Us</Link>
                            <Link to="#">Careers</Link>
                            <Link to="#">Blog</Link>
                            <Link to="#">Terms of Service</Link>
                            <Link to="#">Donate</Link>
                        </div>

                        {/* <!-- Discover --> */}
                        <div className="col-6 col-md-3">
                            <h6>Discover</h6>
                            <Link to="#">Home</Link>
                            <Link to="#">Books</Link>
                            <Link to="#">Authors</Link>
                            <Link to="#">Subjects</Link>
                            <Link to="#">Collections</Link>
                            <Link to="#">Advanced Search</Link>
                            <Link to="#">Return to Top</Link>
                        </div>

                        {/* <!-- Develop --> */}
                        <div className="col-6 col-md-3">
                            <h6>Develop</h6>
                            <Link to="#">Developer Center</Link>
                            <Link to="#">API Documentation</Link>
                            <Link to="#">Bulk Data Dumps</Link>
                            <Link to="#">Writing Bots</Link>
                        </div>

                        {/* <!-- Help --> */}
                        <div className="col-6 col-md-3">
                            <h6>Help</h6>
                            <Link to="#">Help Center</Link>
                            <Link to="#">Contact Us</Link>
                            <Link to="#">Suggesting Edits</Link>
                            <Link to="#">Add a Book</Link>
                            <Link to="#">Release Notes</Link>
                            <div className="footer-icons mt-2">
                                <Link to="#"><i className="bi bi-twitter-x"></i></Link>
                                <Link to="#"><i className="bi bi-github"></i></Link>
                            </div>
                        </div>
                    </div>
                </div>
            </footer>
        </>
    );
}

export default Footer;