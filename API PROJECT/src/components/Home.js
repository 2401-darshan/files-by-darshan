import React from 'react'
import Navbar from './Navbar';
import Footer from './Footer';
import "../css/home.css";

function Home() {
    return (
        <> 
        <Navbar />
            <div className="main-wrapper">
                <div className="content-box">
                    {/* <!-- Welcome Section --> */}
                    <section className="container my-4">
                        <h5 className="mb-4 fs-4">Welcome to Open Library</h5>
                    <div className="row g-3 pb-5">
                        <div className="col-md-4">
                            <div className="card text-center p-3 h-100">
                                <h6>📖 Read Free Library Books Online</h6>
                                <p>Millions of books available through Controlled Digital Lending</p>
                            </div>
                        </div>
                        <div className="col-md-4">
                            <div className="card text-center p-3 h-100">
                                <h6>📅 Set a Yearly Reading Goal</h6>
                                <p>Learn how to set a yearly reading goal and track what you read</p>
                            </div>
                        </div>
                        <div className="col-md-4">
                            <div className="card text-center p-3 h-100">
                                <h6>📚 Keep Track of your Favorite Books</h6>
                                <p>Organize your books using Lists & Reading Log</p>
                            </div>
                        </div>
                    </div>
                </section>

                {/* <!-- Trending Books --> */}
                <div className="container my-4">
                    <h5 className="mb-4 fs-4 text-decoration-underline">Trending Books</h5>
                    <div className="row g-3 mb-5">
                        <div className="col-6 col-md">
                            <img src="https://covers.openlibrary.org/b/id/240727-L.jpg" className="book-cover w-75" alt="Book" />
                                <button className="btn btn-primary mt-4 ms-5 w-50">Borrow</button>
                        </div>
                        <div className="col-6 col-md">
                            <img src="https://covers.openlibrary.org/b/id/8167896-L.jpg" className="book-cover w-75" alt="Book" />
                                <button className="btn btn-success mt-4 ms-5 w-50">Checked</button>
                        </div>
                        <div className="col-6 col-md">
                            <img src="https://covers.openlibrary.org/b/id/9254115-L.jpg" className="book-cover w-75" alt="Book" />
                                <button className="btn btn-success mt-4 ms-5 w-50">Checked</button>
                        </div>
                        <div className="col-6 col-md">
                            <img src="https://covers.openlibrary.org/b/id/153541-L.jpg" className="book-cover w-75" alt="Book" />
                                <button className="btn btn-primary mt-4 ms-5 w-50">Borrow</button>
                        </div>
                        <div className="col-6 col-md">
                            <img src="https://covers.openlibrary.org/b/id/10544177-L.jpg" className="book-cover w-75" alt="Book" />
                                <button className="btn btn-success mt-4 ms-5 w-50">Checked</button>
                        </div>
                        <div className="col-6 col-md">
                            <img src="https://covers.openlibrary.org/b/id/11002209-L.jpg" className="book-cover w-75" alt="Book" />
                                <button className="btn btn-success mt-4 ms-5 w-50">Checked</button>
                        </div>
                    </div>
                </div>

                {/* <!-- classNameic Books --> */}
                <div className="container my-4">
                    <h5 className="mb-4 fs-4 text-decoration-underline">classic Books</h5>
                    <div className="row g-3 mb-5">
                        <div className="col-6 col-md-2">
                            <img src="https://covers.openlibrary.org/b/id/240727-L.jpg" className="book-cover w-75" alt="Book" />
                                <button className="btn btn-success mt-4 ms-5 w-50">Checked</button>
                        </div>
                        <div className="col-6 col-md-2">
                            <img src="https://covers.openlibrary.org/b/id/8167896-L.jpg" className="book-cover w-75" alt="Book" />
                                <button className="btn btn-primary mt-4 ms-5 w-50">Read</button>
                        </div>
                        <div className="col-6 col-md-2">
                            <img src="https://covers.openlibrary.org/b/id/9254115-L.jpg" className="book-cover w-75" alt="Book" />
                                <button className="btn btn-success mt-4 ms-5 w-50">Checked</button>
                        </div>
                        <div className="col-6 col-md-2">
                            <img src="https://covers.openlibrary.org/b/id/153541-L.jpg" className="book-cover w-75" alt="Book" />
                                <button className="btn btn-primary mt-4 ms-5 w-50">Borrow</button>
                        </div>
                        <div className="col-6 col-md-2">
                            <img src="https://covers.openlibrary.org/b/id/10544177-L.jpg" className="book-cover w-75" alt="Book" />
                                <button className="btn btn-success mt-4 ms-5 w-50">Checked</button>
                        </div>
                        <div className="col-6 col-md-2">
                            <img src="https://covers.openlibrary.org/b/id/11002209-L.jpg" className="book-cover w-75" alt="Book" />
                                <button className="btn btn-primary mt-4 ms-5 w-50">Read</button>
                        </div>
                    </div>
                </div>

                {/* <!-- Books We Love--> */}
                <div className="container my-4">
                    <h5 className="mb-4 fs-4 text-decoration-underline">Books We Love</h5>
                    <div className="row g-3 mb-5">
                        <div className="col-6 col-md-2">
                            <img src="https://covers.openlibrary.org/b/id/240727-L.jpg" className="book-cover w-75" alt="Book" />
                                <button className="btn btn-success mt-4 ms-5 w-50">Checked</button>
                        </div>
                        <div className="col-6 col-md-2">
                            <img src="https://covers.openlibrary.org/b/id/8167896-L.jpg" className="book-cover w-75"
                                alt="Book" />
                                <button className="btn btn-primary mt-4 ms-5 w-50">Borrow</button>
                        </div>
                        <div className="col-6 col-md-2">
                            <img src="https://covers.openlibrary.org/b/id/9254115-L.jpg" className="book-cover w-75"
                                alt="Book" />
                                <button className="btn btn-success mt-4 ms-5 w-50">Checked</button>
                        </div>
                        <div className="col-6 col-md-2">
                            <img src="https://covers.openlibrary.org/b/id/153541-L.jpg" className="book-cover w-75" alt="Book" />
                                <button className="btn btn-primary mt-4 ms-5 w-50">Read</button>
                        </div>
                        <div className="col-6 col-md-2">
                            <img src="https://covers.openlibrary.org/b/id/10544177-L.jpg" className="book-cover w-75"
                                alt="Book" />
                                <button className="btn btn-success mt-4 ms-5 w-50">Checked</button>
                        </div>
                        <div className="col-6 col-md-2">
                            <img src="https://covers.openlibrary.org/b/id/11002209-L.jpg" className="book-cover w-75"
                                alt="Book" />
                                <button className="btn btn-primary mt-4 ms-5 w-50">Read</button>
                        </div>
                    </div>
                </div>

                {/* <!-- Recently Returned --> */}
                <div className="container my-4">
                    <h5 className="mb-4 fs-4 text-decoration-underline">Recently Returned</h5>
                    <div className="row g-3 mb-5">
                        <div className="col-6 col-md-2">
                            <img src="https://covers.openlibrary.org/b/id/240727-L.jpg" className="book-cover w-75" alt="Book" />
                                <button className="btn btn-primary mt-4 ms-5 w-50">Read</button>
                        </div>
                        <div className="col-6 col-md-2">
                            <img src="https://covers.openlibrary.org/b/id/8167896-L.jpg" className="book-cover w-75"
                                alt="Book" />
                                <button className="btn btn-success mt-4 ms-5 w-50">Checked</button>
                        </div>
                        <div className="col-6 col-md-2">
                            <img src="https://covers.openlibrary.org/b/id/9254115-L.jpg" className="book-cover w-75"
                                alt="Book" />
                                <button className="btn btn-primary mt-4 ms-5 w-50">Read</button>
                        </div>
                        <div className="col-6 col-md-2">
                            <img src="https://covers.openlibrary.org/b/id/153541-L.jpg" className="book-cover w-75" alt="Book" />
                                <button className="btn btn-success mt-4 ms-5 w-50">Checked </button>
                        </div>
                        <div className="col-6 col-md-2">
                            <img src="https://covers.openlibrary.org/b/id/10544177-L.jpg" className="book-cover w-75"
                                alt="Book" />
                                <button className="btn btn-success mt-4 ms-5 w-50">Checked</button>
                        </div>
                        <div className="col-6 col-md-2">
                            <img src="https://covers.openlibrary.org/b/id/11002209-L.jpg" className="book-cover w-75"
                                alt="Book" />
                                <button className="btn btn-primary mt-4 ms-5 w-50">Borrow</button>
                        </div>
                    </div>
                </div>
            </div>
        </div>

        <Footer />
    </>
  );
}

export default Home